# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file

    input = open(sys.argv[1])
    dictReader = csv.DictReader(input)

    for row in dictReader :                         #creates a dictionary for each team: "team" key : 'teamname'
        teams.append(row)                                                       #        "rating" key: 'hisRating'
        
                                                    #and create a list with all dictionary teams


    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts

    winningCounts = {}
    for team in teams:
        name = team["team"]                     #creates a dictionary of teams where -> "teamName" key : 'value'
        winningCounts[name] = 0                 # initializing 'value' with 0

    for _ in range(N):
        winner = simulate_tournament(teams)
        name = winner[0]["team"]                # execute N tournaments

        winningCounts[name] += 1                #   increments winningCounts value for winner. searching by name


    # Print each team's chances of winning, according to simulation
    for team in sorted(winningCounts, key=lambda team: winningCounts[team], reverse=True):  #sort the dictionary winningCounts by biggest 'value' in winningCounts
        print(f"{team}: {winningCounts[team] * 100 / N:.1f}% chance of winning")            # print one by one with each percentage


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = int(team1["rating"])
    rating2 = int(team2["rating"])
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability


def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    while True:
        teams = simulate_round(teams)                   #simulate_round with teams until rest only 1 in "teams" list. That is the winner.
                                                        # observation: simulate_round will take a list sizeof N teams and return N/2 with winners
        if len(teams) == 1:
            return teams                                #return winner


if __name__ == "__main__":
    main()
