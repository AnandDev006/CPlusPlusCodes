/*
    author : Anand
    Design and implement a HitCounter class that keeps track of requests (or hits). It should support the following operations:

        record(timestamp): records a hit that happened at timestamp
        total(): returns the total number of hits recorded
        range(lower, upper): returns the number of hits that occurred between timestamps lower and upper (inclusive)
        Follow-up: What if our system has limited memory?
*/

#include <bits/stdc++.h>

#define sz(a) int((a).size())
#define pb push_back
#define mp(a, b) make_pair(a, b)
#define all(c) (c).begin(), (c).end()
#define tr(c, i) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define present(c, x) ((c).find(x) != (c).end())
#define cpresent(c, x) (find(all(c), x) != (c).end())
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll REQUESTS_PER_FILE = 3;


/**
 *  in a memory efficient implementation, this would be persisted to disk
 *  once full and only the path and metadata would remain in memory
*/
class PersistedFile
{
public:
    ll startTimeStamp;
    ll endTimeStamp;
    set<ll> requestTimeStamps;
    PersistedFile()
    {
        this->startTimeStamp = this->endTimeStamp = 0;
        requestTimeStamps = set<ll>({});
    }
};

class RequestQuery
{
public:
    PersistedFile *curFile;
    vector<PersistedFile *> prevFiles;
    RequestQuery()
    {
        this->curFile = new PersistedFile;
        this->prevFiles = vector<PersistedFile *>(0);
    }

    void record(ll timeStamp)
    {
        if (curFile->startTimeStamp == 0)
        {
            curFile->startTimeStamp = timeStamp;
        }
        curFile->requestTimeStamps.insert(timeStamp);
        curFile->endTimeStamp = timeStamp;
        if (sz(curFile->requestTimeStamps) == REQUESTS_PER_FILE)
        {
            this->prevFiles.push_back(this->curFile);
            this->curFile = new PersistedFile;
        }
    }

    ll total()
    {
        return REQUESTS_PER_FILE * sz(this->prevFiles) + sz(this->curFile->requestTimeStamps);
    }

    ll range(ll lower, ll upper)
    {
        vector<PersistedFile *> allFiles = this->prevFiles;
        if( sz( this->curFile->requestTimeStamps ) > 0 ) {
            allFiles.push_back(this->curFile);
        }

        set<ll> startTimes;
        set<ll> endTimes;

        for (PersistedFile *file : allFiles)
        {
            startTimes.insert(file->startTimeStamp);
            endTimes.insert(file->endTimeStamp);
        }

        auto start = distance(startTimes.begin(), startTimes.upper_bound(lower)) - 1;
        auto end = distance(endTimes.begin(), endTimes.lower_bound(upper));
        PersistedFile* startFile =  allFiles[start];
        PersistedFile* endFile =  allFiles[end];

        ll startPos = distance( startFile->requestTimeStamps.begin(), startFile->requestTimeStamps.lower_bound(lower) );
        ll endPos = distance( endFile->requestTimeStamps.begin(), endFile->requestTimeStamps.lower_bound(upper));

        ll numOfReq = 0;
        numOfReq += ( REQUESTS_PER_FILE - startPos ) + ( endPos + 1 ) + REQUESTS_PER_FILE * ( end - start - 1 );

        cout << numOfReq << endl;

        return numOfReq;
    }
};

void printArray(const vector<ll> &arr)
{
    cout << "[ ";
    for (ll i = 0; i < sz(arr) - 1; ++i)
    {
        cout << arr[i] << ", ";
    }
    cout << arr[sz(arr) - 1] << " ]" << endl;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    RequestQuery A;
    A.record(1);
    A.record(2);
    A.record(3);
    A.record(4);
    A.record(5);
    A.record(6);
    A.record(7);
    A.record(8);
    A.record(9);
    A.record(10);
    assert( A.range(2,5) == 4);

    return 0;
}