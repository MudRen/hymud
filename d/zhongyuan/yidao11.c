// yidao11.c
inherit ROOM;

void create()
{   
    set("short","���");
    set("long",@LONG
�������̫��ɽ�ĳ�ɽ���룬�ӽ�����ֱͨ���涨����һ·��ɽ����᫣���
ʯ��أ�������ʮ�ּ��ѡ�����ʱ���Ǹ߸ߵ�ɽ�壬ʱ���Ƕ��͵�ɽ�£�·ת��
������ʱ������һƬƽ̹�ĺ�̲��أ��峺�ĺ�ˮ����������
LONG );
    set("exits",([
        "west" : __DIR__"yidao10",
        "northeast" : __DIR__"yidao12" ]) );
    set("outdoors","zhongyuan");
    setup();
}

