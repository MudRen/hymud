 inherit ROOM;
void create()
{
        set("short", "���· ");
        set("long", @LONG
·�������ɽ��������ɽ����չ��������Ũ��֮��������һ��
����ɫ����壬ֱ�������������м�ͷ��ӥ�ڵ͵͵��������裬�·�
�����˵��������
LONG
        );
        set("exits", ([ 
  "east" : __DIR__"palace_path2",
  "northeast" : "/d/tieflag/chuenyu/dustyroad0",

]));
        set("outdoors", "palace"); 
        set("coor/x",100);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
