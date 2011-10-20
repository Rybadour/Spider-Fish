#ifndef ENEMYDATA_H
#define ENEMYDATA_H


class EnemyData
{
  public:
    EnemyData( int type, Uint32 time, int x );
    virtual ~EnemyData();
    int getX();
    Uint32 getTime();
    int getType();
  protected:
  private:
    int _type;
    Uint32 _time;
    int _x;
};

#endif // ENEMYDATA_H
