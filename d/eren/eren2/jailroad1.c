 inherit ROOM;
void create()
{
        set("short", "��ʯ");
        set("long", @LONG
һ��޴����ʯ����·�����룬�������߻����˲��ٿ�϶���ɹ�һ��
�������������һ������ʯ����Ķ���һ��Ҳ��������ֻ�Ǻں�����һ
Ƭ�������ʯ���д������ص��죬�·�һ������Х�У����˲���������
LONG
        );
        set("exits", ([ 
                "south" : __DIR__"yongdao7",
                "north" : __DIR__"jailroad2",
        ]));
        set("indoors", "eren2");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
