// go.c
//Update by daniel
//����go.c����Ϸ�о������õ�,��������ʦ������Ҫ���������޸�
//��ȷʵ��Ҫ�޸�,��֪����һ��.
#include <ansi.h>
// // #pragma save_binary
inherit F_CLEAN_UP;

mapping default_dirs = ([
	"north":	"����",
	"south":	"�Ϸ�",
	"east":		"����",
	"west":		"����",
	"northup":	"����",
	"southup":	"�ϱ�",
	"eastup":	"����",
	"westup":	"����",
	"northdown":	"����",
	"southdown":	"�ϱ�",
	"eastdown":	"����",
	"westdown":	"����",
	"northeast":	"����",
	"northwest":	"����",
	"southeast":	"����",
	"southwest":	"����",
	"up":		"����",
	"down":		"����",
	"enter":	"����",
	"out":		"����",
	"leitai":	"��̨����",
]);

void create() { seteuid(getuid()); }
int main(object me, string arg)
{
       string dest, mout, min, dir, thing_msg;
	object env, obj,obj1, thing;

int result;
	mapping exit;
	object *f_obs;


/*
        eq = me->query("eff_qi");
	mq = me->query("max_qi");
	jing = me->query("jing");
	m_jing = me->query("max_jing");
*/
	if( !arg ) return notify_fail("��Ҫ���ĸ������ߣ�\n");

      if( me->query("id")=="wuwum")
               return notify_fail(HIY"wuwum�����Ҷ�!!!!!!!!!!!!!!!!!!!!!!��\n"NOR);
	if( me->over_encumbranced() )
		return notify_fail("��ĸ��ɹ��أ��������á�\n");

        if (me->query_encumbrance() < 0)
                return notify_fail("��ĸ��ɳ��ֹ��ϣ��������á�\n");

        if (me->is_busy() || me->query("doing"))
		return notify_fail("��Ķ�����û����ɣ������ƶ���\n");

	env = environment(me);
	if(!env) return notify_fail("������Ҳȥ���ˡ�\n");

	if (me->is_fighting()) {
		f_obs = me->query_enemy();
       if (objectp(f_obs[0])&&5 + random((int)me->query("dex")) <=
			random((int)f_obs[0]->query("dex"))) {
			me->start_busy(1);
message_vision(HIM "$N���Ʋ��ã�ת��Ҫ�ߣ���$nһ��������ǰ�����ߣ���û��ô���ף�\n" NOR, me, f_obs[0]);
			return notify_fail("������ʧ�ܡ�\n");
        }
else
{
  message_vision(YEL"$N�����뿪����$nһ��"
                                                       "��ס�����ţ��������"
                                                        "������û�ţ�\n" NOR,
me, f_obs[0]);
                                        tell_object(me, "�㱻��ס��ȥ·��\n");
       return notify_fail("������ʧ�ܡ�\n");

		}
	}

	if( !mapp(exit = env->query("exits")) || undefinedp(exit[arg]) ) {
        if( query_verb()=="xg"){
		    if(!environment(me)->query("outdoors")&&(int)me->query("qi")>10&&(int)me->query("jing")>10){if((int)me->query("qi") > (int)me->query("max_qi")/2)
		       {
		       	me->add("jing",-1);
		       	me->add("qi",-3);
          write( "��Ӵ�� ��һ��С��ײ����ǽ��!\n" );
			return 1;
		}
		       else { me->add("qi",-3);
          write("��Ӵ�� ��һ��С��ײ����ǽ��!\n" );
		              return 1;
		        }}
		      else  return notify_fail("�������û�г�·��\n");}
		else
			return 0;
	}


	dest = exit[ arg ];

	if( !(obj = load_object(dest)) )
	{
	   if(file_size(file_name(environment(me))+".c")>0)
	   {
	   message("channel:wiz",HIG"\n����ͼ���顽 ����"+environment(me)->query("short")+"("+file_name(environment(me))+")"+"�����д����ٸ�����\n\n"NOR,users());
	   log_file("map_error","����"+environment(me)->query("short")+"("+file_name(environment(me))+")"+"�����д����ٸ�����\n");
	   }
           write( "��Ҫȥ������û����ͨ,��֪ͨ������Ա��\n");
           return 1;
        }
           if ( !(obj = find_object(dest)) )
	    	return notify_fail( sprintf( "�޷��� %s �ƶ���\n", dest ) );
	obj1 = find_object(dest);

	if(obj1->query("wiz_only")&&!wizardp(me))
	   return notify_fail("����ֻ�й�����Ա���ܽ�ȥ��\n");
	if(obj1->query("building"))
	   return notify_fail("���ﻹ��ʩ�������Ժ�������\n");


	result = env->valid_leave(me, arg);

	if(env->query("hxsdmigong"))
return 1;

	if ( result < 0 ) return 1;
	else if ( !result ) return 0;

	if( !undefinedp(default_dirs[arg]) )
		dir = default_dirs[arg];
	else
		dir = arg;

	if( me->is_fighting() ) {
		mout = me->name() + "��" + dir + "��Ķ����ˡ�\n";
		min = me->name() + "����ײײ�����˹�����ģ����Щ�Ǳ���\n";
	}
// end of part
         else {
/*
                if( me->query("gender") == "Ů��") {
                     mout = "һ��ٻӰ��" + dir + "�뿪��\n";
                    min = "һ��ٻӰ���˹�����\n";
		}
                else {
                      mout = "һ����Ӱ��" + dir + "�뿪��\n";
                      min = "һ����Ӱ���˹�����\n";
		}
*/
//�ƺ���δ���Ҳ�ɼ�ȥ,����������Ƿ��µĴ���,��ȷ����ɼ�ȥ.
	        if (objectp(thing = me->query_temp("armor/cloth")))
			thing_msg = "����" + thing->query("name");
		else
                        thing_msg = "һ˿����";
	        if (objectp(thing = me->query_temp("weapon")))
			thing_msg += "��ִ" + thing->query("name");
		if ( me->query("race") == "Ұ��")
		{
			mout = me->name() + "������" + dir + "һ�ܾ���ʧ�ˡ�\n";
			min = me->name() + "���ش��˳�������������������š�\n";
		}
		else
		{
			if ( me->query_temp("is_riding"))
			{
				mout = me->name()+"����"+me->query_temp("is_riding")+"��" + dir + "���۶�ȥ��\n";
                              min = me->name() + thing_msg + "����"+me->query_temp("is_riding")+"һ·���۶�����\n";
			}

                           else if ( arg == "leitai")
			{
				mout = me->name()+"˫�����ţ��������Σ�����Ծ����̨��\n";
				min = me->name()+"����̨��һԾ�������ȵ�����̨�ϡ�\n";
			}
			else
			{
				mout = me->name() + "��" + dir + "�뿪��\n";
                            min =  me->name() + thing_msg + "���˹�����\n";
			}
		}
	}

        if ( !me->query("env/no_msg")||me->query_temp("msg")>time() )
	message( "vision", mout, environment(me), ({me}) );
	if( me->move(obj) ) {
              me->remove_all_enemy();
        if ( !me->query("env/no_msg")||me->query_temp("msg")>time() )
		message( "vision", min, environment(me), ({me}) );
		me->set_temp("pending", 0);
		all_inventory(env)->follow_me(me, arg);
		return 1;
	}

	return 0;
}

void do_flee(object me)
{
	mapping exits;
	string *directions;

	if( !environment(me) || !living(me) ) return;
	exits = environment(me)->query("exits");
	if( !mapp(exits) || !sizeof(exits) ) return;
	directions = keys(exits);
	tell_object(me, "�������һ���������...\n");
	main(me, directions[random(sizeof(directions))]);
}

int help(object me)
{
	write(@HELP
ָ���ʽ : go <����>

������ָ���ķ����ƶ���

HELP
    );
    return 1;
}
