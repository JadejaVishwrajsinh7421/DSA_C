while (save != NULL)
    {
        printf("the nodes are\n->");
        printf("%d->", save->info);
        save = save->link;
    }
}