// poison.c ��������
// Modified by Java Mar.1998
inherit SKILL;

void create() { seteuid(getuid()); }
string type() { return "knowledge"; }
int valid_learn(object me)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
        if (!myfam)
return notify_fail("�㲻�����ޣ����嶾�̵��ӣ���������������\n");
    if (!myfam || (myfam["family_name"] != "������") && (myfam["family_name"] != "�嶾��"))
       return notify_fail("�㲻�����ޣ����嶾�̵��ӣ���������������\n");

    if ((me->query_skill("taoism",1) > 1) ||
        (me->query_skill("mahayana",1) > 1) ||
        (me->query_skill("buddhism",1) > 1))
        return notify_fail("������"+RANK_D->query_respect(me)
      +"�Ѿ�ѧ���������ɵ��ķ�����ôȴ��ѧ���ǲ��ܵĶ�����\n");

    return 1;
}
void skill_improved(object me)
{
    mapping myfam;
    myfam = (mapping)me->query("family");
        if (!myfam)
return notify_fail("�㲻�����ޣ����嶾�̵��ӣ���������������\n");

}

