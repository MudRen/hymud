 inherit ROOM;
#include <ansi.h> 
void create() 
{
        set("short", "�����");
        set("long", @LONG
������խ��һ���ţ����������ߡ�������խ������ռ�ĵط�ȴ���խ����
��û�����ƣ�Ҳû�б�־��ֻ����һյ�ۺ�ɫ�ĵơ�������ʱ�򣬾ͱ�ʾ��ط���
��ʼӪҵ����ʼ׼�����������Ǯ�ˡ���Ϩ�ŵ�ʱ�������Ｘ����δ�������˳�
������ȻҲû���˽�ȥ�����ﾹ������������ĵط���
LONG
        );
        set("exits", ([ 
        "north": __DIR__"road5",
        "south": __DIR__"xiaojinku2",
        ]));
        set("objects", ([
        ]) );
        set("coor/x",-1140);
        set("coor/y",170);
        set("coor/z",0);
        setup();
        replace_program(ROOM);
}  
