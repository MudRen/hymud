 inherit ROOM;
void create()
{
    set("short", "�η�");
        set("long", @LONG
�����ǹ�Ѻ���˵ĵط�������ʮ�߼������η���û�д�齱��죬ֻ�м��ѿݻ�
ɢ����������ζ�ĵ��ݣ���ʱ���д��������Ľ����ܹ�����֪������Ʈ���ĸ���
֮������������η������źڰ����η����ʱ��Զ���������˵ĺ�������
LONG
        );
    set("indoors", "jinan");
    set("coor/x",70);
    set("coor/y",1870);
    set("coor/z",0);
        set("valid_startroom",1);
        set("no_magic", 1);
    set("exits", ([ /* sizeof() == 3 */
        "north" : __DIR__"dalao1",
    ]));
        setup();
}
void init()
{
        this_player()->set("startroom", base_name(this_object()));

} 
