// ��ʯ�� /d/menpai/shennong/luanshi_hou.c

inherit ROOM;



void create()
{   
    set("short",    "��ʯ��");
    set("long", @LONG
�ڴ�ѵ���ʯ���У����ż��ڴ�������������ũ�������һ���󺺵�ָ����
��æ���ջ�������ҩ���Ǵ�ɴ�ɵ����̾��Ǵ�����ð���ġ����̵�ζ����Ϊ��
�֣�һ���֪������Ǿ綾֮��Աߵ�é����������ж���ÿݻ��ˡ�
LONG
    );
    set("exits",    ([
        "southwest" :   __DIR__"dong_shanyao",
        "northwest" :   __DIR__"luanshi1",
    ]) );
    set("objects",  ([
        __DIR__"npc/asheng"         :   1,
        __DIR__"npc/bangzhong"      :   2,
    ]) );
    set("outdoors", "wuliang");
    setup();
}

