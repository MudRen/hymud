 inherit ROOM;
void create()
{
        set("short", "���Ƶ�"); 
        set("long", @LONG
��һ��������´ߡ�������ǽ����������ķ��Ƶ�������ɫ�ĵ�·�������￪ʼ
������չ���������̵����֣�����տ���ĺ�ˮ����չ�����С�Զɽ�������ɫ��
�������·������У������������ء�����������򲢲�Զ������һ����ˮ��һ����
�֡�ȴ���ѽ��쳾������ɽ�⡣                                  
LONG); 
        set("type","road");
        set("exits",([
        "west":__DIR__"me",
        "southeast":__DIR__"fydao2",
                ]) );
        set("outdoors", "chenxiang");
        set("coor/x",-480);
        set("coor/y",-540);
        set("coor/z",0);
        setup();
}
int valid_leave(object who,string dir)
{
        if(userp(who) && random(10))
          {
           who->move(this_object());
           return notify_fail(""); 
          }
        return 1;
}
