// daizhou.c
inherit ROOM;

void create()
{   
    set("short","����");
    set("long",@LONG
�����Ѿ��Ǳ���ǰ�ߣ����ܽ��ǳ�ɽ���룬����ɽ���ӹ�֮�����Խ��е�¥
���̨������ƽ��ϡ�٣����񲻶ֻ࣬��ɽ����ϡϡ�������Щũ����ᶼ��
�������õġ�����ɽ���ϲ�ʱ��һȺɽ�������޵سԲݡ�����ɽ�����Ǵ��ݳǣ�
С����̡����߾������Ź��ˡ�
LONG );
    set("exits",([
        "southwest": __DIR__"yidao4",
        "northwest": __DIR__"yanmen_guan",
        "northeast": __DIR__"shanlu1" ]) );
    set("outdoors","zhongyuan");
    setup();
}

