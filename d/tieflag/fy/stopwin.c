 inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
���������������������ֺú���ǰ�ڶ࣬���������Ҳ��˺õò����ˡ��˴�
���ϰ�������ĸ����������������Ľ�ʨ����ͷ������Ĵ��ƹ����ǵ������ͷ��
���ӡ�����ı���Ӧ�о��У����Բ������򲻵��ġ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"nwind4",
        ]));
        set("objects", ([
                __DIR__"npc/weaponer": 1,
                __DIR__"npc/biaoshi_wang" : 1,
        ]) );
        set("coor/x",-10);
        set("coor/y",40);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}      
