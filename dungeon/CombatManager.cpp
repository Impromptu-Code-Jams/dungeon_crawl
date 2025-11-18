void goto_xy(int x, int y)
{
    std::cout << "\033[" << (y + 1) << ";" << (x + 1) << "H";
}

void CombatManager::display(int x, int y)
{
    goto_xy(x, y);
    std::cout << "Hello World!";
}
