 inherit ROOM;
void create()
{
        set("short", "�Ǳ�С·");
        set("long", @LONG
����������С·�����������졣·���Ա��Ƿ��ƳǵĻ��Ǻӣ��ӵ�����һ
�߾��Ǹߴ�ķ��Ƴǳ�ǽ�ˡ���������Կ�����ǽ��ֵ�ڵ�ʿ����վ�ڡ��ӵ���
�������̲ݡ�΢�������һ�ɵ���������Ϣ������������ԼԼ����������������
����
LONG
        );
        set("exits", ([ /* sizeof() == 4 */ 
  "west" : __DIR__"fynorth",
  "east" : __DIR__"road5",
]));
        set("outdoors", "fengyun"); 
        set("coor/x",30);
        set("coor/y",160);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
