 inherit ROOM;
void create()
{
        set("short", "��ɽ·");
        set("long", @LONG
��������������·��ȴ��ƽ̹���������߶���ïʢ�����֣����
����ʱ�������������������ķҷ�����һ����ʹ�����ؿ��ʣ�����
һ�з��ա���Զ��ǰ������һ���ʯ��һ��Сͤ�ӡ�
LONG
        );
        set("exits", ([
                "northdown" : __DIR__"gate",
                "southup" : __DIR__"xuanwumen",
                "west" : __DIR__"pine1",
                "east" : __DIR__"pine3",
        ]));
        set("outdoors", "wudangfy");
        set("coor/x",100);
        set("coor/y",-90);
        set("coor/z",10);
        setup();
        replace_program(ROOM);
}     
