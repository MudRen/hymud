// yidao1.c
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
        "south": __DIR__"jinyang_chengxia",
        "east" : __DIR__"yidao2" ]) );
    set("outdoors","zhongyuan");
    setup();
}

