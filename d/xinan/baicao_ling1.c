#include <room.h>
inherit ROOM;


void create()
{
        set("short", "�ٲ���");
        set("long", @LONG
�ٲ�����������ů�������������ƣ����ϵ�ɽ�����������˸ߴ����ľ����
ʹɽ������������Ҳ���Ǽ�����̫����������ɽ���������İ�������Ϫˮ��
����ˮ�߳����˲�֪���Ļ��ݣ���˵�������������ҩ�ġ��ݴ��ﾭ���ж���
��û�����˵�ս�ľ���
LONG
        );
        set("exits", ([
                "southdown"     : __DIR__"shandao0",
                "north"         : __DIR__"baicao_ling2",
        ]));
        set("search_things",([
            "ɽ��" : __DIR__"obj/heshouwu" ,
                                  ])
       );

        setup();



}
