 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���������Ƕ������ˣ���������ͨ��ɽ���һ��·�����ź������ĳ���û��ʲ
ô��ͬ�����������˸�ʾ��ͨ�����˵���������������ڶ��ű��˷��֣�����
�˹ٸ���ץס�ġ�
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"egate",
  "west" : __DIR__"ecloud4",
  "north" : __DIR__"hall",
])); 
        set("outdoors", "fengyun");
        set("coor/x",50);
        set("coor/y",0);
        set("coor/z",0);
        set("coor/x",50);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
