#include <iostream>
#include <vector>
#include <string>

// The player's inventory
std::vector<std::string> inventory;

// Function to present a situation to the player
void presentSituation(const std::string &situation, const std::vector<std::string> &options)
{
  std::cout << situation << "\n";

  for (int i = 0; i < options.size(); i++)
  {
    std::cout << i + 1 << ". " << options[i] << "\n";
  }
}

// Function to handle the player's choice
void handleChoice(int choice)
{
  switch (choice)
  {
  case 1:
    std::cout << "You picked up a key.\n";
    inventory.push_back("key");
    break;
  case 2:
    if (inventory.empty())
    {
      std::cout << "You don't have any item to use.\n";
    }
    else
    {
      std::cout << "You used the " << inventory.back() << ".\n";
      inventory.pop_back();
    }
    break;
  case 3:
    std::cout << "You engaged in a conversation. It was fruitless.\n";
    break;
  default:
    std::cout << "Invalid choice.\n";
    break;
  }
}

int main()
{
  std::cout << "You will lose.\n";

  // Initializing vector in a way compatible with older C++ versions
  std::vector<std::string> options;
  options.push_back("Pick up the key");
  options.push_back("Use an item");
  options.push_back("Talk to yourself");

  while (true)
  {
    presentSituation(
        "You are in a room. There is a locked door, and a key on the table.",
        options);

    int choice;
    std::cin >> choice;

    if (std::cin.fail())
    {
      std::cin.clear();                                                   // clear error state
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard 'bad' character(s)
      std::cout << "Invalid choice. Please enter a number.\n";
      continue;
    }

    handleChoice(choice);

    if (choice == 2 && !inventory.empty())
    {
      if (inventory.back() == "key")
      {
        std::cout << "You used the key to unlock the door, but another locked door appeared. You're stuck forever.\n";
        break;
      }
    }
  }

  return 0;
}
