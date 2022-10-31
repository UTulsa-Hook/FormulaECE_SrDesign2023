// Some queue stuff...
struct node
{
    double index;
    double data1;
    double data2;
    struct node *link;
} * front, *rear;

// Some queue stuff...
void insert(double pozInput[3])
{

    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->index = pozInput[0];
    temp->data1 = pozInput[1];
    temp->data2 = pozInput[2];
    temp->link = NULL;
    if (rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->link = temp;
        rear = temp;
    }
}

void delet()
{
    struct node *temp;
    temp = front;
    if (front == NULL)
    {
        // printf("Queue underflow\n");
        front = rear = NULL;
    }
    else
    {
        // printf("The deleted element from the queue is: %f\n", front->data1);
        front = front->link;
        free(temp);
    }
}

void serch(int index, double X_old_predicted[2])
{
    struct node *temp;
    temp = front;
    int cnt = 0;

    while (temp)
    {
        if (temp->index == index)
        {
            X_old_predicted[0] = temp->data1;
            X_old_predicted[1] = temp->data2;
        }
        temp = temp->link;
    }
}

int size()
{
    struct node *temp;
    temp = front;
    int cnt = 0;

    while (temp)
    {
        // printf("%d\n", temp->data);
        temp = temp->link;
        cnt++;
    }
    // printf("%d\n", cnt);
    return cnt;
}

// End of queue files. Use the above functions to implement the queue as done in MATLAB

// Matrix Dot product:
// Used in CheckHalfPlane

double vec1[2] = {X[0] - P[0], X[1] - P[1]};

for (int i = 0; i < 2; i++)
    result += vec1[i] * N[i];
return result;

// "norm" function used in controlCircle
double num1;
double num2;
sqrt((num1 * num1 + num2 * num2));

// To calculate inverse in controlLine

// R is the rotation matrix as built in MATLAB

for (int i = 0; i < 3; i++)
{
    determinant = determinant + (R[0][i] * (R[1][(i + 1) % 3] * R[2][(i + 2) % 3] - R[1][(i + 2) % 3] * R[2][(i + 1) % 3]));
}

for (int i = 0; i < 3; i++)
{
    for (int j = 0; j < 3; j++)
    {
        inverse[i][j] = ((R[(j + 1) % 3][(i + 1) % 3] * R[(j + 2) % 3][(i + 2) % 3]) - (R[(j + 1) % 3][(i + 2) % 3] * R[(j + 2) % 3][(i + 1) % 3])) / determinant;
    }
}
