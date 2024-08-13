#include <bits/stdc++.h>
#include <random>
using namespace std;

const int POPULATION_SIZE = 100;
const int MAX_GENERATIONS = 1000;
const double MUTATION_RATE = 0.01;
const int LOG_INTERVAL = 100;

vector<int> pots, trees;
int n;

random_device rd;
mt19937 g(rd());

struct Chromosome
{
    vector<int> genes;
    int fitness;

    Chromosome(int size) : genes(size), fitness(0)
    {
        iota(genes.begin(), genes.end(), 0);
        shuffle(genes.begin(), genes.end(), g);
    }
};

int calculateFitness(const vector<int> &genes)
{
    vector<int> sums(n);
    for (int i = 0; i < n; i++)
    {
        sums[i] = pots[i] + trees[genes[i]];
    }
    sort(sums.begin(), sums.end());
    int sum_diff = 0;
    for (int i = 1; i < n; i++)
    {
        sum_diff += sums[i] - sums[i - 1];
    }
    return sum_diff;
}

Chromosome crossover(const Chromosome &p1, const Chromosome &p2)
{
    Chromosome child(n);
    int crossPoint = rand() % n;
    for (int i = 0; i < crossPoint; i++)
    {
        child.genes[i] = p1.genes[i];
    }
    vector<bool> used(n, false);
    for (int i = 0; i < crossPoint; i++)
    {
        used[p1.genes[i]] = true;
    }
    int j = crossPoint;
    for (int i = 0; i < n; i++)
    {
        if (!used[p2.genes[i]])
        {
            child.genes[j++] = p2.genes[i];
        }
    }
    child.fitness = calculateFitness(child.genes);
    return child;
}

void mutate(Chromosome &chr)
{
    if ((double)rand() / RAND_MAX < MUTATION_RATE)
    {
        int i = rand() % n;
        int j = rand() % n;
        swap(chr.genes[i], chr.genes[j]);
        chr.fitness = calculateFitness(chr.genes);
    }
}

void logGeneration(int generation, const vector<Chromosome> &population)
{
    auto minmax = minmax_element(population.begin(), population.end(),
                                 [](const Chromosome &a, const Chromosome &b)
                                 { return a.fitness < b.fitness; });

    double avgFitness = 0;
    for (const auto &chr : population)
    {
        avgFitness += chr.fitness;
    }
    avgFitness /= population.size();

    cout << "Generation " << generation << ":" << endl;
    cout << "  Best fitness: " << minmax.first->fitness << endl;
    cout << "  Worst fitness: " << minmax.second->fitness << endl;
    cout << "  Average fitness: " << avgFitness << endl;
    cout << "  Best solution: ";
    for (int i = 0; i < min(10, n); i++)
    { // แสดงเพียง 10 ยีนแรก
        cout << minmax.first->genes[i] << " ";
    }
    if (n > 10)
        cout << "...";
    cout << endl
         << endl;
}

int geneticAlgorithm()
{
    vector<Chromosome> population;
    for (int i = 0; i < POPULATION_SIZE; i++)
    {
        population.emplace_back(n);
        population.back().fitness = calculateFitness(population.back().genes);
    }

    cout << "Initial population created." << endl;
    logGeneration(0, population);

    for (int generation = 1; generation <= MAX_GENERATIONS; generation++)
    {
        sort(population.begin(), population.end(),
             [](const Chromosome &a, const Chromosome &b)
             { return a.fitness < b.fitness; });

        if (generation % LOG_INTERVAL == 0)
        {
            logGeneration(generation, population);
        }

        vector<Chromosome> newPopulation;
        for (int i = 0; i < POPULATION_SIZE; i++)
        {
            int p1 = rand() % (POPULATION_SIZE / 2);
            int p2 = rand() % (POPULATION_SIZE / 2);
            Chromosome child = crossover(population[p1], population[p2]);
            mutate(child);
            newPopulation.push_back(child);
        }
        population = move(newPopulation);
    }

    sort(population.begin(), population.end(),
         [](const Chromosome &a, const Chromosome &b)
         { return a.fitness < b.fitness; });

    cout << "Final result:" << endl;
    logGeneration(MAX_GENERATIONS, population);

    return population[0].fitness;
}

int main()
{
    cin >> n;
    pots.resize(n);
    trees.resize(n);
    for (int i = 0; i < n; i++)
        cin >> pots[i];
    for (int i = 0; i < n; i++)
        cin >> trees[i];

    srand(time(0));

    cout << "Starting Genetic Algorithm..." << endl;
    cout << "Population size: " << POPULATION_SIZE << endl;
    cout << "Max generations: " << MAX_GENERATIONS << endl;
    cout << "Mutation rate: " << MUTATION_RATE << endl;
    cout << "Problem size (n): " << n << endl
         << endl;

    int result = geneticAlgorithm();
    cout << "Best sum of diff found: " << result << endl;
    return 0;
}