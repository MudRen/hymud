inherit ROOM;
int do_xue(string arg);
void create()
{
    set("short", "��ٸ");
    set("long", @LONG
�Լ�վ�ڳ����İ���ʯ��֮�ף�ʯ��ֱͨ���Ϸ����������ߡ�ʮ��
����ľ޴�ƽ̨����ͷ��ȥ�������ĺ�ɫ���׺����ǧ��ű�ʯ�����飬
��ʶ�Ŀ�������Ǻӣ������ҹ�գ��������յ�һƬ������������
�����Ķ���·�����Ȼ����һ���εض�������������ΰ���ǡ���Ρ
��׳���ĳ�¥������Ķ��ǵ����ܷ��ߣ������۴��ڰ���ʯ̨�ϣ���
̩ɽѹ�������ȳ�����¥��Ҫ���ư��硢���������ʯ�����ߵĹ㳡�ϣ�
�������龹ȫ���гɷ���ı�ٸ��ͭ�ˡ���ٸ��ʯ�񡭡�������ӣ���
˵Ҳ�м���֮�ڣ�������׳���������ݡ��㳡�ϣ�һ�����������ѽ���
��ҫ����Ŀ�Ĺ��󣬾����ǽ��ӻ㼯��һ�볯����һ���׹�������ˮ��
��ȥ��
�������ٸ���ﶼ���ŵ������Ÿ������ƣ���̬���졣
LONG
    );
    set("exits", ([
           "east":__DIR__"shidao3",
    ]));
    setup();
}
void init()
{
    add_action("do_xue", "kan");
}
int do_xue(string arg)
{
    object me;
    me = this_player();
    if ( !arg || ( arg != "ٸ" ) )
        return notify_fail("ʲô��\n");
    if ( (int)me->query_skill("literate", 1) < 1)
        return notify_fail("���Ǹ���ä����ѧ���Ļ�(literate)�ɡ�\n");
    if ( (int)me->query("jing") < 50)
        return notify_fail("��ľ�������\n");

    if ( me->is_busy())
        return notify_fail("������æ��\n");

    me->receive_damage("jing", me->query("jing")/10);
    message_vision("$N��ʼģ��ѧϰ��Щ��ٸ�ĸ��ֶ�����\n", me);
    me->start_busy(2);
    if ( (int)me->query_skill("blade", 1) < 601)
    {
        me->improve_skill("qinhuang/blade", me->query_int());
        //me->set("blade",1);
        return 1;
    }
    write("�������ٸ����һ�ض��������Ѿ�û��ʲô��ѧ���ˡ�\n");
    return 1;
}
