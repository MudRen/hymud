// ��ɽ�� /d/menpai/shennong/dong_shanao.c
// By lala, 1998-01-26

inherit ROOM;



void create()
{
    set("short",    "ɽ��");
    set("long", @LONG
�ƹ�Сé�ݣ�С·��ת�˸��䣬����һ��ɽ�ꡣ����ɢ���������ʯ���Ե�
��Ϊ������������ɽ�������ܿ���С�ݵ��ݶ���ɽ�µ�ũ�һ����ɽ�紵����
��ŷ����Լ��Ѿ����úܸ��ˡ�
LONG
    );
    set("exits",    ([
        "north"     :   __DIR__"dong_shanyao",
        "westdown"  :   __DIR__"wuqian",
    ]) );
    set("outdoors", "wuliang");
    setup();
}
