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
        "northwest":__DIR__"fydao2",
        "east":"/d/baiyun/plainroad",
                ]) );
        set("outdoors", "chenxiang");
        set("coor/x",-220);
        set("coor/y",-550);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
} 
