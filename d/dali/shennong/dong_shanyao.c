// ��ɽ�� /d/menpai/shennong/dong_shanyao.c

inherit ROOM;



void create()
{   
    set("short",    "��ɽ��");
    set("long", @LONG
ת��ɽ�ֻ꣬��һ�����ʯ֮���������Ŷ�ʮ���ˡ��˴���һ����С������
����һ�����֮�ϣ��߳����ˣ����һ��ɽ����ӣ���̬�����ư�����ʯ֮����
��ɴ�ɵ�����ð��������һ�������˺ܲ��������ζ��
LONG
    );
    set("exits",    ([
        "south"     :   __DIR__"dong_shanao",
        "northeast" :   __DIR__"luanshi_hou",
    ]) );
    set("objects",  ([
        __DIR__"npc/sikong_xuan"    :   1,
        __DIR__"npc/gao_laozhe"     :   1,
        __DIR__"npc/bangzhong"      :   2,
    ]) );
    set("outdoors", "wuliang");
    setup();
}
