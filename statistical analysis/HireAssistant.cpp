// Hire Assitant - Probabilistic Analysis and Randomized Algorithms

/*
    Problem:
    The hiring assistant problem is a theoretical problem in computer science and applied probability.
    The problem involves hiring a candidate from a pool of applicants in a sequential manner while 
    minimizing the expected cost of hiring. The problem can be described as follows: There are N 
    applicants for a position, and they arrive in a random order, one at a time. Each applicant
    has a quality score which is drawn independently from a uniform distribution over [0,1]. 
    Once an applicant is interviewed, the employer must decide whether to hire the applicant 
    or not. If the applicant is hired, the process stops and the employer incurs a cost equal 
    to the quality score of the hired applicant. If the applicant is not hired, the process 
    continues, and the employer moves on to the next applicant. The goal is to minimize the 
    expected cost of hiring. There are various algorithms to solve this problem, including 
    the "immediate decision" algorithm and the "explore-then-commit" algorithm. The performance 
    of these algorithms is often analyzed in terms of the competitive ratio, which is the 
    ratio of the expected cost of the algorithm to the optimal cost (i.e., the cost of hiring the best candidate).
    ​The randomized hiring assistant problem is a fundamental problem in the area of online 
    decision making, where decisions are made in real-time with incomplete information. It has 
    applications in fields such as operations research, economics, and machine learning.
*/

/*
    General Notes
        Differnetiating the cost between the run-time and the cost incurred of the algorithms calculations
        Cost = O(nci + mch), where n is the number of candidates, ci is the interviewing calculations, m is the
            the number of hired candidates, and ch is the cost of the hiring process. The interviewing should 
            be expensive and so should the hiring process. 
        Practices the paradigm of maintaining the best element - in this case, the best candidate. 
        Worst case is that every day we hire a new candidate, therefore, it would be in our best interest to 
        randomize the list of the candidates that we interview. This adds a randomized factor that will likely
        increase the efficiency of the average scenario. 
*/

/*
    Pseudocode
        1 2 3 4 5 6
        best ← 0 ✄ candidate 0 is a least-qualified dummy candidate fori←1ton
        do interview candidate i
        if candidate i is better than candidate best
        then best ← i
        hire candidate i
        The cost model for this problem differs from the model described in Chapter 2. We are not concerned with the running time of HIRE-ASSISTANT, but instead with the cost incurred by interviewing and hiring. On the surface, analyzing the cost of this algorithm may seem very different from analyzing the running time of, say, merge sort. The analytical techniques used, however, are identical whether we are analyzing cost or running time. In either case, we are counting the number of times certain basic operations are executed.
        Interviewing has a low cost, say ci, whereas hiring is expensive, costing ch. Let m be the number of people hired. Then the total cost associated with this algorithm is O(nci + mch). No matter how many people we hire, we always inter- view n candidates and thus always incur the cost nci associated with interviewing. We therefore concentrate on analyzing mch, the hiring cost. This quantity varies with each run of the algorithm.
        This scenario serves as a model for a common computational paradigm. It is often the case that we need to find the maximum or minimum value in a sequence by examining each element of the sequence and maintaining a current “winner.” The hiring problem models how often we update our notion of which element is currently winning.
        Worst-case analysis
        In the worst case, we actually hire every candidate that we interview. This situation occurs if the candidates come in increasing order of quality, in which case we hire n times, for a total hiring cost of O(nch).
        It might be reasonable to expect, however, that the candidates do not always come in increasing order of quality. In fact, we have no idea about the order in which they arrive, nor do we have any control over this order. Therefore, it is natural to ask what we expect to happen in a typical or average case.
*/

/*
    Exercises
        1) In HIRE-ASSISTANT, assuming that the candidates are presented in a random order, 
        what is the probability that you will hire exactly one time? What is the probability 
        that you will hire exactly n times?
            1/n

        2) In HIRE-ASSISTANT, assuming that the candidates are presented in a random order,
        what is the probability that you will hire exactly twice?
            (1/n) (first candidate probability) * (1/(n - 1)) (second candidate probability)
            simplified: 1/n(n - 1)

        3) Use indicator random variables to compute the expected value of the sum of n dice.
            3.5N
*/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Candidate {
    string name;
    int id;
    int score;
    
    Candidate(string n, int i, int s) : name(n), id(i), score(s) {}
};

// Immediate decision. Assumes the first candidate is the best and hires the first candidate that is better than the first.
int immediateDecisionHiring(const vector<Candidate>& candidates) {
    int n = candidates.size();
    int best = -1;
    int hired = -1; 

    for (int i = 0; i < n; i++) {
        if (candidates[i].score > best) {
            best = candidates[i].score;
            hired = i;
        }

        if (i >= n / M_E) {
            break;
        }
    }

    return hired;
}


// Explore-then-commit algorithm: Balancing Exploration and Exploitation:
// Exploration: Interviewing a subset of candidates to gain information about candidate quality.
// Exploitation: Selecting the best candidate based on the information gathered during exploration.
// Finding clues from our subsets and creating dynamic decisions on continuining or stopping the exploration.

int exploreThenCommitHiring(const vector<Candidate>& candidates) {
    // TODO: finish algorithm
    return 0;
}

int main() {
    vector<Candidate> candidates;

    candidates.push_back(Candidate("John", 1, 10));
    candidates.push_back(Candidate("Alice", 2, 8));
    candidates.push_back(Candidate("Bob", 3, 5));
    candidates.push_back(Candidate("Eve", 4, 15));
    candidates.push_back(Candidate("Charlie", 5, 12));
    candidates.push_back(Candidate("Grace", 6, 20));

    int hiredCandidate = immediateDecisionHiring(candidates);

    cout << "Hired candidate index: " << hiredCandidate << endl;
    cout << "Hired candidate name: " << candidates[hiredCandidate].name << endl;

    return 0;
}