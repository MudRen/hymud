// ���� /d/city/chuzhou/npc/obj/zi_yan.c

inherit ITEM;

void create()
{
    set_name("����", ({"zi yan", "yan"}));
    set_weight(5000);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("long", @LONG
������ɽ���Ͳ����������Ͷ�����������������˾������Ϊ��׫������ͨ����
���õ����ȵ����ڻʵ۽�������Ʒ���⡣
LONG
        );
        set("unit", "��");
        set("value", 5300);
    }
}
