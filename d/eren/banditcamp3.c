 inherit ROOM;
void create()
{
        set("short", "�Ͼ�");
        set("long", @LONG
Ӫ��������һ�������ľ��ܣ�������ˮͰ���ҵص����ڵ��ϡ����¿�ȥ���ڹ�¡
�˵ز����ף�����һ��ʯ�ӣ���������ž��׹�����ھ��ڻ��죬ԭ���Ѿ��ɿ��˲�֪
�����ꡣ������˩��һƥû����ɵ�����
LONG
        );
        set("exits", ([ 
                "east" : __DIR__"banditcamp2",
                        ]));
        set("objects", ([
                __DIR__"npc/horse" : 1,
        ]));
        set("outdoors", "eren"); 
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}     
