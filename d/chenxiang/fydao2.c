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
        "northwest":__DIR__"fydao1",
        "southeast":__DIR__"fydao3",
                ]) );
        set("outdoors", "chenxiang");
        set("coor/x",-470);
        set("coor/y",-550);
        set("coor/z",0);
        setup();
}
int valid_leave(object who,string dir)
{
        if(userp(who) && random(5))
          {
           who->move(this_object());
           return notify_fail("");
         }
        return 1;
}  
