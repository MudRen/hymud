 inherit ROOM;
void create()
{
        set("short", "�������");
        set("long", @LONG
���Ƿ��Ƴ���Ψһ����֣��ǳ�������������ĵط����ϰ������������˵
�ǵ����̫�ӵ���ʦ�����Ǿ����������飬���������͵����Ȼ��̰�ӡˢ����
���ﲻ���кܶ��ɧ����ϲ����ʫ�ʣ�����һЩ��ǳ�Ĺ����飬�����о�������ǿ
���塣
LONG
        );
        set("exits", ([
                "east" : __DIR__"nwind1",
        ]));
        set("objects", ([
                __DIR__"npc/bookseller": 1,
        ]) );
        set("coor/x",-10);
        set("coor/y",10);
        set("coor/z",0);
        set("coor/x",-10);
        set("coor/y",10);
        set("coor/z",0);
        setup();
        replace_program(ROOM); 
}    
