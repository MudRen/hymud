 inherit ROOM;
void create()
{
        set("short", "���Ƶ�"); 
        set("long", @long
��һ��������´ߡ�������ǽ����������ķ��Ƶ�������ɫ�ĵ�·�������￪ʼ
������չ���������̵����֣�����տ���ĺ�ˮ����չ�����С�Զɽ�������ɫ��
�������·������У������������ء�����������򲢲�Զ������һ����ˮ��һ����
�֡�ȴ���ѽ��쳾������ɽ�⡣                                  
long); 
        set("type","road");
        set("exits",([
        "westup":__DIR__"huanghe6",
        "eastdown":__DIR__"huanghe8",
                ]) );
        set("outdoors", "shanxi");
        set("coor/x",-10);
        set("coor/y",-430);
        set("coor/z",30);
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