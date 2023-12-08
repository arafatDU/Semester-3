#include<bits/stdc++.h>
using namespace std;

struct job
{
    char jobid[20];
    int startTime;
    int finishTime;
    int compatibility;
} jobs[100];
int numOfJobs;

void readInput(){
    cin>>numOfJobs;
    for(int i=0; i<numOfJobs; i++){
        cin>>jobs[i].jobid>>jobs[i].startTime>>jobs[i].finishTime;
        jobs[i].compatibility = 1;
    }
    for(int i=0; i<numOfJobs; i++){
        cout<<jobs[i].jobid<< "  "<<jobs[i].startTime<< "  "<<jobs[i].finishTime<< "  ";
        cout<<jobs[i].compatibility<<endl;
    }


}



bool compare(struct job job1, struct job job2)
{
    return job1.finishTime<job2.finishTime;
}

void iterative(){
    for(int i=0; i<numOfJobs; i++){
         if(jobs[i].compatibility != 0){
            for(int j=i+1; j<numOfJobs; j++){
                if(jobs[j].startTime < jobs[i].finishTime){
                    jobs[j].compatibility = 0;
                }
            }
         }
    }
}


void recursiveSelector(int i){
    int m = i + 1;
    while (m <= numOfJobs && jobs[m].startTime<jobs[i].finishTime){
        jobs[m].compatibility = 0;
        m++;
    }
    if(m <= numOfJobs){
        recursiveSelector(m);
    } else return ;
}



int main()
{
    freopen("input2.txt", "r", stdin);
    readInput();
    sort(jobs, jobs+numOfJobs, compare);

    cout<<"__________________________"<<endl;

    recursiveSelector(0);

    for(int i=0; i<numOfJobs; i++){
        if(jobs[i].compatibility == 1){
            cout<<jobs[i].jobid<< "  "<<jobs[i].startTime<< "  "<<jobs[i].finishTime<< "  ";
            cout<<jobs[i].compatibility<<endl;
        }
    }

    cout<<"__________________________"<<endl;
    

    return 0;
}