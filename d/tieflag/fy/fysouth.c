 inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
���Ƿ��Ƴ��ϱߵ��м����ϱ�����ɴ˺�ᡣ�ϴ���ɽ��ˮ��ֱ����
�������½ӷ��ƾ�������ͨ���Ϻ��ڡ����������ò�����һ���������Ϸ�
�ͱ�����չ��
LONG
        );
        set("exits", ([ 
  "north" : "/d/tieflag/fy/sgate",
  "east"  : __DIR__"sroad4",
  "west"  : __DIR__"sroad3",
  "south" : "/d/tieflag/fy/road0", 
]));
        set("objects", ([
        __DIR__"npc/wind_solider" : 1,
        ]) );
      
        set("outdoors", "fengyun");
        set("coor/x",0);
        set("coor/y",-160);
        set("coor/z",0);
        setup();
}  
