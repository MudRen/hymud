// yidao2.c
inherit ROOM;

void create()
{   
    set("short","���");
    set("long",@LONG
����������н������ݣ���̫ԭֱ�����Źأ��ǳ�͢Ϊ�������Źط��ض���
�������ģ�·��һ�ɣ�������ʯ��������ʹ������Ҳ������¡������������
������ɽ��֮�У�������ϵ��ɽ������������ɽ�����ϲ�ʱ���������ɳ۶�����
�������صĳ�����
LONG );
    set("exits",([
        "west": __DIR__"yidao1",
        "north" : __DIR__"yidao3",
        "northeast" : __DIR__"xiaolu4"  ]) );
    set("outdoors","zhongyuan");
    setup();
}

