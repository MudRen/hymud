// shop.c   �����
// Ffox 98-4-30 10:09

inherit ROOM;

void create()
{
    set( "short", "�����");
    set( "long", @LONG
һ�ҹ��ܵ����˿���С���ӣ�����������ǳ����εģ������ĸ��˶���̸��
���ơ��ϰ�����һλ��ʮ����ĸ�Ů������ش�ƫƧ��������ΪС���Ͼ���ôһ
��С���ӣ�Զ�����������·�����ﶼ������������Ϣ��һϴ���ϵķ糾����
��˵����������Զ���������������һ���ο����
LONG );
    set( "item_desc", ([
    "south" : "�Ƕ�����䣬Զ����Ϣ֮���ڡ�\n",
]) );
    set( "exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"shoproom",
    "east" : __DIR__"street",
]) );
    set( "objects", ([
    __DIR__"npc/laoban" : 1,
]) );
    setup();
}

int valid_leave(object me, string dir)
{
    if( dir == "south" )
      if( !me->query_temp("hami/sleep") )
        return notify_fail("��û�и�Ǯ����ô��ȥ�����Ϣ�أ�\n");
    return :: valid_leave(me,dir);
}
