// yidao4.c
inherit ROOM;

void create()
{   
    set("short","���");
    set("long",@LONG
����������н������ݣ���̫ԭֱ�����Źأ��ǳ�͢Ϊ�������Źط��ض���
�������ģ�·��һ�ɣ�������ʯ��������ʹ������Ҳ������¡������������
������ɽ��֮�У���������̨ɽ�������Ǳ�����ɽ�����ϲ�ʱ���������ɳ۶�
�����������صĳ�����
LONG );
    set("exits",([
        "south": __DIR__"yidao3",
        "northeast": __DIR__"daizhou" ]) );
    set("outdoors","zhongyuan");
    setup();
}

