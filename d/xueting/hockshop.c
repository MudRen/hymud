// Room: /d/changan/hockshop.c ����

inherit ROOM;

void create()
{
        set("short", "�żǵ���");
        set("long", @LONG
������ѩͤ��һ�Ҳ���ĵ��̣�һ���ţ���㿴���˸߸ߵ�
��̨����̨��һ��һ���Һ�ĵ��ϰ壬����æ�ŵ��ű��˵Ķ�����
����ͣ�Ľ��ţ��յ�����ĳĳһ����ֵ���١��Աߵ��ʷ�������
�����ʣ�������������⻹������¡���ſ���һ���ͺڷ�������
��(sign)�����ó�������Ѿ��ܹ����ˡ�
LONG
        );
        set("item_desc", ([
                "sign": @TEXT
���̽��׵ķ���:
[ value | gujia ]     : ����
[ pawn | dang ]       : �䵱
sell                  : ��
[ redeem | shu ]      : ���
list                  : �б�
[ buy | mai ]         : ��
TEXT
        ]) );
        set("exits", ([
                "west" : __DIR__"street02",
        ]));

	set("objects",([
		__DIR__"npc/zhangboss"	: 1,
      ]));
        setup();
}