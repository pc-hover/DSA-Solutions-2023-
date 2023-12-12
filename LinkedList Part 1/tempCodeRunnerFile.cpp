 if (ptr != nullptr && ptr->next != nullptr)
    {
        ptr->data = (ptr->next)->data;
        ptr->next = ptr->next->next;
        delete(ptr->next);
    }
    return;