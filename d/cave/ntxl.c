 // Copyright (C) FengYun Workshop
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit ROOM;
string door();
void create()
{
        set("short", "������·");
        set("long", @LONG
�����ܵͣ�����ʹ��վ��վ��ֱ��������һֱ�ε����յ������ڵ�ˮ��ˮ�ʻ�
�Ƿ�ճ�����µİ��ӷ���¡¡���������ƺ�������ת�䡣·��ͷ�Ǽ�ʯ�ݣ���Լ��
���谵�ĵƹ���ŷ���͸����
LONG
        );
    set("exits", ([ /* sizeof() == 4 */
                "north" : __DIR__"tzdx",
//              "south" : __DIR__"ntxm",
        ])); 
        set("item_desc", ([
                "door" : (: door :),
                "��" : (: door :),
                "�ŷ�" : (: door :),
        ]));
        set("objects", ([
        __DIR__"npc/guard2": 1,
                        ]) );
    set("indoors", "cave");
    set("coor/x",-60);
    set("coor/y",-40);
    set("coor/z",-20);
        setup();
} 
string door(){
        object me;
        me = this_player();
        
        tell_object(me, "���ű�һ�Ѵ������������ţ����ϲ����˻ƺ�ɫ�����⡣\n");
        return "";
}        
