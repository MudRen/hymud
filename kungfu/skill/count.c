
// count.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
        object ob;

        mapping myfam;
        myfam = (mapping)me->query("family");
        if ((int)me->query_skill("bibo-shengong", 1) < 20)
                return notify_fail("��ı̲��񹦻��̫ǳ��\n");
        if( (int)me->query_skill("literate",1) < 50 )
                return notify_fail("��Ķ���д��̫�ͣ�û�а취ѧ�������ԡ�\n");

        return 1;
}

int practice_skill(object me)
{
        return notify_fail("��������ֻ����ѧ(learn)�������������ȡ�\n");
}
