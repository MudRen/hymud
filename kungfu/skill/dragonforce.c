// �����硤���μǡ��汾��������
/* <SecCrypt CPL V3R05> */
 
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) { return 1; }



int practice_skill(object me)
{

   if( (int)me->query_skill("dragonforce",1) >= 200 )
     return notify_fail("��������ķ���������ˣ���������ʦ�������̰ɣ�\n");

   if( (int)me->query_temp("dragonforce_practice") < 1 )
     return notify_fail("�������������ɺ��޽�չ����Ҫѱ������ĺ��������������ķ���\n");

        if( (int)me->query("qi") < 30 )
                return notify_fail("�����������\n");
   if( (int)me->query("qi") < 30 )
                return notify_fail("����񲻹���\n");
        if( (int)me->query("neili") < 10 )
                return notify_fail("�����������");
        me->receive_damage("qi", 30);
   me->receive_damage("jing", 30);
        me->add("neili", -10);
  // me->add_temp("dragonforce_practice",-1);
        return 1;
}

