 inherit ROOM;
void create()
{
        set("short", "ƫ��");
        set("long", @LONG
ƫ����һ��÷��ʽ����С������߼���������������У��ұ߼�����Ҥ��������
���ڲ���ʱ�ʻ��ܣ�������̵�е����������һ���������ϣ�����������������
���֮���ߣ�Ҳ��һ�Ը߼�����������ƿ���㱸��
LONG
        );
        set("exits", ([ 
                "north": __DIR__"redhouse0",
        ]));
        set("item_desc", ([
        
         ]));
        set("objects", ([
                __DIR__"npc/maid":      1,
        ]));
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
}
