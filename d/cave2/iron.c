 // TIE@FY3 ALL RIGHTS RESERVED
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
�������ر���ر�ߣ��ıڿտգ�ʲôҲû�У�һ����վ��
���棬�ͺ���վ�ڿ�Ұ���Ƶġ�������տ�����ɭ���������룬
�������վ���������ã����߲Ұ�ɫ�����ã�����ӵ����һ��
���˵�Ѫ���ѻ�������������������������
���Ű��������Ͼ�Ȼ������Щ��ī����ᡣ
LONG
        );
        set("exits", ([ 
                "center" : __DIR__"center",
                        ]));
        set("objects", ([
//              __DIR__"npc/nun" : 2,
        ]) );
        set("indoors", "eren");
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}     
