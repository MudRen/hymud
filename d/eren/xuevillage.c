 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�ú�ׯ");
        set("long", @LONG
�ú�ׯ����Ѧ��ׯ��ׯ�����ǵ���һ������п���ٵ��̹��񸫺�ɨ��̫��ɽ
��Ѧ�󡣲���������������һ�����ú�ׯ�Ѿ��������ӡ�ǽ�����ֳ����ƣ�������
���������ε�ס���紵�Ŵ���ʱ����ͣ�ء���񡱷��졣
LONG
        );
        set("exits", ([ 
                "northeast" : __DIR__"road1e",
                "south": __DIR__"xuevillage2",
        ]));
        set("objects", ([
                
        ]) );
        set("coor/x",0);
        set("coor/y",0);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}      
