//by dewbaby@sk_sjsh
//�Ž������

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        int lvl;
	string msg;
	int extra;
	int i;
	object weapon,victim;
	int damage;
	int flag;
	string fskill,sskill,bskill,pfname,pskill;
        int ap, dp, fp, pp,count;

        string str;
        int j;
int skill, neili_wound, qi_wound;

        weapon = me->query_temp("weapon");

      if (! target) target = offensive_target(me);
  if (! objectp(weapon = me->query_temp("weapon")) ||
            (string)weapon->query("skill_type") != "sword")
                return notify_fail("��ʹ�õ��������ԣ�\n");

	if(me->is_busy())
		return notify_fail("������û�գ���\n");



        if (! target || ! me->is_fighting(target))
                return notify_fail("ֻ����ս���жԶ���ʹ�á�\n");
                
//	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
//		return notify_fail("�������ֻ�ܿ���ʹ�á�\n");		
	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("�������������\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("�������������\n");

       if( !wizardp(me) &&(int)me->query_skill("love-sword", 1) < 500 )
		return notify_fail("��ı����⹦����!���ܹ�ͨʹ�ã�\n");

	if(!wizardp(me) && (int)me->query_skill("bluesea-force", 1) < 500 )
		return notify_fail("��ı����ڹ�������!���ܹ�ͨʹ�ã�\n");


//	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
//		return notify_fail("�����ѧ̫�࣬�޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("��Ľ������黹�������޷��Ա����书��ͨʹ�ã�\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("�㻹û��ͨ����ɽ�۽�! �޷��Ա����书��ͨʹ�ã�\n");

        //if ( !wizardp(me) && me->query_skill_mapped("sword") == "love-sword")
          //      return notify_fail("�����Ž��������ʹ�ñ��ž�ѧ!\n");


        if ( !wizardp(me) && me->query_skill_mapped("force") != "bluesea-force")
                return notify_fail("��ʹ�ñ����ڹ������ʹ�ñ��ž�ѧ!\n");

//        if( !wizardp(me) && me->query_temp("weapon") )
//              return notify_fail("�������ֲ���ʹ�ñ��ž�ѧ!\n");

        msg = HBWHT "$N��ͨ�㵴��ѧ��ʹ�����㵴�ľ�ѧ֮���裡\n" NOR;
message_vision(msg, me, target);               
victim=target;
if (me->query("hyvip")==4) 
	{me->add("neili",-500);}
	else
	{me->add("neili", -me->query("max_neili")/7);}


     
        lvl = me->query_skill("love-sword", 1);
         message_vision("
"HIR"$N�����ݺᣬ��Ӱٿ�����·�ն�������¾���\n"NOR,me,victim);
             victim->receive_wound("qi",random(lvl)+1,me);
             COMBAT_D->report_status(victim);
message_vision("
"HIY"--�������ڳ���ʱ�������ڳ���ĺĺ--"NOR"
"HIR"$Nƽ��һ����������㯣��·���������³���\n"NOR,me,victim);
             victim->receive_wound("qi",random(lvl)+1,me);
             COMBAT_D->report_status(victim);

message_vision("
"HIY"--���ĵؽ�����ʱ��ֻ����˼�޾���--"NOR"
"HIR"$N������ƣ����ö�Ŀ���·���������»���\n"NOR,me,victim);
             victim->receive_wound("qi",random(lvl)+1,me);
             COMBAT_D->report_status(victim);

message_vision("
"HIY"--�´������ղ��ڣ�Ϊ����������--"NOR"
"HIR"$N������˸������Ʈ�����·𶯳�����������\n"NOR,me,victim);
             victim->receive_wound("qi",random(lvl)+1,me);
             COMBAT_D->report_status(victim);

message_vision("
"HIY"--���鲻�ƶ���࣮һ�绹��ǧ����\--"NOR"
"HIR"$N����¶����ҷ����𣬷·�ó�����������\n"NOR,me,victim);
             victim->receive_wound("qi",random(lvl)+1,me);
             COMBAT_D->report_status(victim);

message_vision("
"HIY"--����ɴ���׷�䣮ֻ�ǵ�ʱ���Ȼ--"NOR"
"HIR"$N����һ�����������ǣ��·��ճ������¹⻪\n"NOR,me,victim);
victim->receive_wound("qi",random(lvl)+1,me);

             COMBAT_D->report_status(victim);
         



message_vision("\n
"HIY"$N�����뽣�ѿ�ʼ���˶�����һ�ּ��������������Ķ����������Ƿ���ô��Ȼ
"HIY"$N��ͫ����������"+weapon->name()+""HIY"�������Ĵ��˳���
"HIY"�����˼��Ĳ�λ���˳������̳�ʱ��Ȼ���������˼��ı仯
"HIY"���ϸ���û����������һ��������û���κ�����˭��ȥ����һ��������ȥ����\n"NOR,me,victim);
if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)
  {
   message_vision(HIR"Ѫ��ҫ���ֲ��ã����õ��������ǣ�����һ�ּ��ţ�Ѫ��Ҳ�ܿ������\n"NOR, me);
                damage = me->query_skill("love-sword",1);
                target->receive_damage("qi", damage*4,me);
                target->receive_wound("qi", damage*4,me);
  }
   else
  {
   message_vision(HIR"Ѫ��ҫ���ֲ��ã����õ��������ǣ�����һ�ּ��ţ�Ѫ��Ҳ�ܿ������\n"NOR, me);
  }


  message_vision(HIW"$N�����յ�"+weapon->name()+""HIW"�·���ɱ�˵�������������������һ�У���һ�в������죮������׼ȷ"
                 HIW"$n���еĶ�����������һ��ʹ��ʱ��Ȼ��ȫ��ͣ�٣�Ȼ�����ͽ�����һƬ����"
                 HIW"����Ľ�Ӱ�������Ѫ����������ת������ת�죬�ɴ����"
                 HIW"��Ȼ�ֻ���һ��ƥ����Ĳʺ죬��ɫ�ʺ죬�߽�����ɶ��ˣ�ǧ����\n"NOR,me,victim);
if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)

     {
message_vision(sprintf(HIC"$n��$N����ɫ����������ȫ�������˺����ۣ�\n"NOR),me,victim);
                damage = me->query_skill("bluesea-force",1);
                target->receive_damage("qi", damage*4,me);
                target->receive_wound("qi", damage*4,me);
     }
     else
     {
           message_vision(sprintf(WHT"$n"+WHT"����ֹˮ��������$N"+WHT"�Ľ��ƣ�\n"NOR),me,victim);
     }
           
       message_vision(HIW"$N��������Ҹ����һ�������⣮һ����һ���Ľ��⣮���������ʢ��
"HIW"��ؼ�Ʈҷ��һ���������⣬�����ƻã���������¹�Ͷ������Ĵ� 
"HIW"��һ�������졢���١����򵥡���ȥ��ƽ�����森���� 
"HIW"Ȼ��ȴ�ǡ���˼���Ρ�һǧ��һʽ�����еľ�����ɱ�У�
"HIW"��"HIR"�轣����������ն"HIW"�� \n"NOR, me);
if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)

     {
 message_vision(HIW"һ��է�������Ķ���ϸ������������Ѫ�ڶ��ĺ�⣬�Խ���͸�˳���
"HIW"Ѫ���Ľ�������̫�����°�������$n����Χ
"HIW"$nֻ�����ֿ졢���桢�־������ޡ���������ꡢ����һ��
"HIW"��"HIC"���쳾·"HIW"��\n"NOR,me,victim);
        message_vision(HBRED"$N�ķ������$n���˷��磬��ʧ�ڷ��쳾֮�У�\n"NOR,me,victim);
                damage = me->query_skill("love-sword",1);
                target->receive_damage("qi", damage*4,me);
                target->receive_wound("qi", damage*4,me);
     }
     else
     {
           message_vision(sprintf(WHT"$n"+WHT"����ֹˮ��������$N"+WHT"�Ľ��ƣ�\n"NOR),me,victim);
     }



       message_vision(CYN"$NЦ��΢��������·����һ����Ӱ��һ˲����������һ��������"
                            HIW"\t����"BLINK""HIR"  ���ΰ��壮��������"NOR""HIW"  ����\n"NOR,me,victim);
          message_vision(HIY"����"HIR"��   ��"HIY"����\n"NOR,me,victim);
            message_vision(HIW"�������磬�������Σ���ɫ�ͷף������Ľ��⣬��ͬ�������ŷ绪��\n�ռ�Ϊ�����������"
                                       +"��ʹ⻪�����������һ�����������ڿ������֣�\n��Ѥ��һ������һ��Ļ������\n"NOR,me,victim);
          message_vision(HIY"����"HIR"��   ��"HIY"����\n"NOR,me,victim);
            message_vision(HIW"�����Լ������һ����������������ɱ�⣬�������˷���������ɽ�����Ļ�����\n"+
                                         "����ɢ����������Ŀ�Ĺ�ʣ�Ѫ�Ƶ��ʺ�ɫ���������ң����Ѳ�ɫ���Ρ���\n"NOR,me,victim);
          message_vision(HIY"����"HIR"��   ��"HIY"����\n"NOR,me,victim);
            message_vision(HIW"���׺��𣬴�ظ������������һ������ǿ�⣬�Ѳ���������������������쭺���\n"+
                                         "�·�Ǳ���ص׵�ŭ�������ζ����������죬�������������ƥ����\n"NOR,me,victim);

if( random(me->query("combat_exp") ) > (int)target->query("combat_exp")/4 || random(3)==0)

     {

 message_vision(MAG"$N�Ľ�����������ƻã�$n��������һ����ɼ��ǵ��˺�ȴ����֪��\n"NOR,me,victim);
                damage = me->query_skill("love-sword",1);
                target->receive_damage("qi", damage*4,me);
                target->receive_wound("qi", damage*4,me);
     }
     else
     {
                  message_vision(HIB"$n������$N�Ĺ��ƣ����첻���ı��˿�����\n"NOR,me,victim);
     }

        //me->add_temp("apply/sword", -lvl/3);
        me->start_busy(4);
        return 1;
}