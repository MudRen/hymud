 inherit ROOM;
void create()
{
        set("short", "ɽׯǰԺ");
        set("long", @LONG
�����װ�ι��Ӷ����š�Ժ�ӵ����ܰ߰ߵ������Ż�ɫ��ö�塣
Ժ�ӵ���ǳ��ſž����޼�����÷������ÿ���캮�ض�֮ʱ��ѩ�׶�
��͸�ŷۺ��÷������š�
LONG
        );
        set("exits", ([ 
  "south" : __DIR__"gate",
  "north" : __DIR__"bamboo_hall",
]));
        set("outdoors", "resort"); 
        set("coor/x",-1230);
        set("coor/y",50);
        set("coor/z",-10);
        setup();
        replace_program(ROOM);
}   
