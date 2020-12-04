// ask.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>
string query_inquiry(object ob);
inherit F_CLEAN_UP;
string  zuji(string str);
#include "/quest/giveaskgift.c"
void zujinpc(object me,object obj);
void zujinpc2(object me,object obj);

string *family_fame = ({
        "������",
        "�䵱��",
        "ؤ��",
        "ȫ���",
        "��ɽ��",
        "����μ�",
        "����Ľ��",
        "ѩɽ��",
        "���չ�",
        "������",
        "�һ���",
        "������",
        "��Ĺ��",
        "������",
        "��ң��",
        "����ɽ��",
        "�������",
        "����������", 	
        "������",
        "��������",
        "����",
        "������",
        "�嶾��",
        "���ư�",
        "����",
        "������",
        "�컨��",
        "��ɽ��",
        "̩ɽ��",
        "�����",
        "��ɽ��",
        "��ɽ��",
        "÷ׯ",
        "�������",
"������",
"������",
"���͵�",
"�����",
"�㵴��",	
});
string *msg_dunno = ({
	"$nҡҡͷ��˵����û��˵����\n",
	"$n�ɻ�ؿ���$N��ҡ��ҡͷ��\n",
	"$n�����۾�����$N����Ȼ��֪��$P��˵ʲô��\n",
	"$n�����ʼ磬�ܱ�Ǹ��˵���޿ɷ�档\n",
	"$n˵������....���ҿɲ��������������ʱ��˰ɡ�\n",
	"$n����һ�����˵�����Բ������ʵ�����ʵ��û��ӡ��\n",
});

int main(object me, string arg)
{
	string dest, topic, msg;
	object ob,letter,room2,env,letter2,*inv;
	mapping inquiry;
        string str;
int exp,pot,j,i,k;
        string room;
string file,envn;
string *roomlines;
string location,local,fname;
string *dir2;
mapping quest;
string my_file;
object newob, *ob_list;

    string week, month, year, day, time,hydata;
    string check;
 	    

	seteuid(getuid());
			str=read_file("/log/NEWS");
sscanf(ctime(time()), "%s %s %s %s %s", week, month, day, time, year);
        if( me->is_busy() )
                return notify_fail("����Ъ������˵���ɡ�\n");

	if( !arg || sscanf(arg, "%s about %s", dest, topic)!=2 )
		return notify_fail("��Ҫ��˭ʲô�£�\n");

	if( !objectp(ob = present(dest, environment(me))) )
		return notify_fail("����û������ˡ�\n");

	if( !ob->is_character() ) {
		message_vision("$N����$n��������....\n", me, ob);
		return 1;
	}

	if( !living(ob) ) 
		return notify_fail("������Ȱ�" + ob->name() + "Ū�ѡ�\n");

	if( !ob->query("can_speak") ) {
		message_vision("$N��$n�����йء�" + topic + "������Ϣ������$p��Ȼ�������˻���\n", me, ob);
		return 1;
	}

if (me->query_temp("big5") && userp(me) && topic!="" ) 
topic=LANGUAGE_D->Big52GB(topic); 


	if( !INQUIRY_D->parse_inquiry(me, ob, topic) )
		message_vision("$N��$n�����йء�" + topic + "������Ϣ��\n", me, ob);

if (me->is_busy()) return notify_fail("������æ��\n");
if (ob->is_busy() && topic!="�ؼ�") return notify_fail("������æ��\n");


//me->start_busy(1);


if( me!=ob && userp(ob) && ob->query_temp("hdjoblb")  && ob->query_temp("hdjobtg") && topic=="news" )
{
	//ob->start_busy(1);
me->set_temp("tjoblx",0);
me->delete_temp("tjoblx");	
if (me->query_temp("tjobstart")>=3)
{
message_vision("$n˵��,��˵����˺ܶ��£�ȴûһ����ɣ�\n", me, ob);	
return 1;
}

if (me->query_condition("taskjob_busy"))
{
message_vision("$n˵��,��Ž��˱���������һ�������ɡ�\n", me, ob);	
return 1;
}
me->apply_condition("taskjob_busy",16);


me->add_temp("tjobstart",1);	
message_vision("$n˵��,����һ����Ҫ�鷳��һ�¡���������:" + ob->query_temp("hdjobsc") + " ��ɺ�������͡�\n", me, ob);
if( ob->query_temp("hdjoblb")=="����")
{
ob->set_temp("ishm",1);
me->clear_condition("taskjob_busy");
}
}

if( me!=ob && userp(ob) && ob->query_temp("hdjoblb")  && ob->query_temp("hdjobtg") && topic=="job" )
{
	me->set_temp("tjoblx",0);
me->delete_temp("tjoblx");	
me->set_temp("nbjob38",1);

exp=388+random(188);
if ((int)me->query_temp("hdjobsl",1)>=90) me->set_temp("hdjobsl",90);
message_vision("$n���˵�ͷ��\n", me, ob);
if( ob->query_temp("hdjoblb")=="��ս")
{
message_vision("$n˵��,�����䣬�������æ����Ҫ��������ս�ˡ�\n", me, ob);
ob->delete_temp("hdjoben");
ob->delete_temp("hdjoblb");
ob->delete_temp("hdjobtg");
ob->delete_temp("hdjobsc");	
addnl(me,"exp",exp);
me->apply_condition("taskjob_busy",16);
return 1;
}	

if( ob->query_temp("hdjoblb")=="����")
{
if (environment(ob))
{
		inv = all_inventory(environment(ob));
		for(i=0; i<sizeof(inv); i++) {
			if( !userp(inv[i]) && inv[i]->query("name")==ob->query_temp("hdjobtg") ) 
{
if (exp> 800) exp=800;
if ((int)me->query_temp("hdjobsl",1)>=1) exp=exp+((int)me->query_temp("hdjobsl",1)*30);
addnl(me,"exp",3000+exp);	
addnl(ob,"exp",2000+exp);
ob->delete_temp("hdjoben");
ob->delete_temp("hdjoblb");
ob->delete_temp("hdjobtg");
ob->delete_temp("hdjobsc");	
me->clear_condition("taskjob_busy");
me->set_temp("tjobstart",0);
me->delete_temp("tjobstart");
message_vision("$n˵��,�����������ڼ�����"+inv[i]->query("name")+"��\n", me, ob);

return 1;
}				
}
		}


if (!ob->query_temp("ishm"))
{
message_vision("$n˵��,�������æ��û��ȥ���ˡ�\n", me, ob);
ob->delete_temp("hdjoben");
ob->delete_temp("hdjoblb");
ob->delete_temp("hdjobtg");
ob->delete_temp("hdjobsc");	
me->apply_condition("taskjob_busy",18);
addnl(me,"exp",exp);
}
else
{
message_vision("$n˵��,�Ѿ����˽�����������ˡ�\n", me, ob);	
}	
return 1;
}

message_vision("$n˵��,����һ����Ҫ�鷳��һ�¡���������:" + ob->query_temp("hdjobsc") + "����ɺ�������͡�\n", me, ob);
if (!me->query("zhuanshen")) addnl(me,"exp",exp);
addnl(ob,"exp",exp);
if (ob->query_temp("hdjoblb")=="�ͻ�")
{
        letter = new("/quest/huowo");
        letter->set("hwtg",ob->query_temp("hdjobtg"));
        letter->set("long"," "+ob->query_temp("hdjobsc")+"\n");
        letter->move(me);
	
}

if (ob->query_temp("hdjoblb")=="����")
{
    ob_list = users();
    ob_list = sort_array(users(), "sort_user", this_object());

        newob = ob_list[random(sizeof(ob_list))];
if(newob->query("id")==ob->query("id")) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob)) newob = ob_list[random(sizeof(ob_list))];
if(!living(newob)) newob = ob_list[random(sizeof(ob_list))];

if(newob->query("id")==ob->query("id")) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob)) newob = ob_list[random(sizeof(ob_list))];
if(!living(newob)) newob = ob_list[random(sizeof(ob_list))];

if(newob->query("id")==ob->query("id")) newob = ob_list[random(sizeof(ob_list))];
if(wizardp(newob)) newob = ob_list[random(sizeof(ob_list))];
if(!living(newob)) newob = ob_list[random(sizeof(ob_list))];

	
if (newob)
{
env=environment(newob);
if (env)
{
dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");
}
if (newob)
{
message_vision("$n˵��:�������͵�" + newob->query("name") + "("+ newob->query("id") + ")�����ϣ���ɺ�������͡�\n", me, ob);
        letter = new("/quest/liwo");
        letter->set("hwtg",newob->query("id"));
        letter->set("long","�͸�"+envn+"������:"+newob->query("name")+"("+ newob->query("id") + ")�����\n");
        me->set_temp("hdjob2sc","�������"+envn+"������:"+newob->query("name")+"("+ newob->query("id") + ")��\n");
        me->set_temp("hdjob2tg",newob->query("id"));
        letter->move(me);
}
else return 0;
}
}
		
if (ob->query_temp("hdjoblb")=="��ɱ")
{
room2=load_object(ob->query_temp("hdjobtg"));
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/boss");
       letter->move(ob->query_temp("hdjobtg"));
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("killbyn",me->query("id"));
zujinpc(me,letter);	
message_vision("$n˵��,��˵�ҵ�����:" + letter->query("name") + "��"+room+"������������´����˰�,��ɺ�������͡�\n", me, ob);

}		


if (ob->query_temp("hdjoblb")=="Ѱ��") 
{
ob->set_temp("hdjobxh",ob->query_temp("hdjobtg"));
}
me->set_temp("hdjob2lb",ob->query_temp("hdjoblb"));
if (ob->query_temp("hdjoblb")!="����")
{
me->set_temp("hdjob2tg",ob->query_temp("hdjobtg"));
me->set_temp("hdjob2sc",ob->query_temp("hdjobsc"));
}

if (ob->query_temp("hdjoblb")=="����")  me->set_temp("roomjob",ob->query_temp("hdjobtg"));
if (ob->query_temp("hdjoblb")=="��̽")  me->set_temp("roomjob",ob->query_temp("hdjobtg"));
if (ob->query_temp("hdjoblb")=="����")  me->set_temp("roomjob",ob->query_temp("hdjoben"));
if (ob->query_temp("hdjoblb")=="��ɱ") me->set_temp("hdjob2sc",ob->query_temp("hdjobsc")+"������"+letter->query("name"));

ob->delete_temp("hdjoben");
ob->delete_temp("hdjoblb");
ob->delete_temp("hdjobtg");
ob->delete_temp("hdjobsc");
	 return 1;
}


if( me!=ob && !userp(ob) && ob->query_temp("nhdjoblb")  && ob->query_temp("nhdjobtg") && topic=="job")
{	
me->set_temp("tjoblx",0);
me->delete_temp("tjoblx");
if (me->query_temp("tjobstart")>=3)
{
message_vision("$n˵��,��˵����˺ܶ��£�ȴûһ����ɣ�\n", me, ob);	
return 1;
}
if (me->query_condition("taskjob_busy"))
{
message_vision("$n˵��,��Ž��˱���������һ�������ɡ�\n", me, ob);	
return 1;
}
me->apply_condition("taskjob_busy",16);

env=environment(ob);
dir2=explode(base_name(env),"/");
envn=zuji(dir2[1])+"-"+env->query("short");
my_file = read_file("/log/taskjob");
my_file= replace_string(my_file,envn,"(��ִ��)");
write_file("/log/taskjob",my_file,1);
exp=88+random(88);
if (!me->query("zhuanshen")) addnl(me,"exp",exp);
me->set_temp("tjoblx",0);
me->delete_temp("tjoblx");
me->add_temp("tjobstart",1);
me->set_temp("nbjob37",1);
if ((int)me->query_temp("nhdjobsl",1)>=90) me->set_temp("nhdjobsl",90);
message_vision("$n˵��,������һ���¡���������:" + ob->query_temp("nhdjobsc") + "��\n", me, ob);
if (ob->query_temp("nhdjoblb")=="�����ͻ�")
{
        letter = new("/quest/task/huowo");
        letter->set("nhwtg",ob->query_temp("nhdjobtg"));
        letter->set("long"," "+ob->query_temp("nhdjobsc")+"\n");
        letter->move(me);
message_vision("$n˵��,������鷳����һ��Ҫ�ú��͵�,�Է��������������ء�\n", me, ob);
	
}
if (ob->query_temp("nhdjoblb")=="�߽�����")
{
room2=load_object(ob->query_temp("nhdjobtg"));
if (room2) local=room2->query("short");
me->set_temp("nhdjob2tg",ob->query_temp("nhdjobtg"));
me->set_temp("roomjob",local);
message_vision("$n˵��,��˵�о�����һ·��ɱ������һ��Ҫ�����ô�ú�ɽ��\n", me, ob);
}

if (ob->query_temp("nhdjoblb")=="�����ػ�")
{
room2=load_object(ob->query_temp("nhdjobtg"));
if (room2) local=room2->query("short");
me->set_temp("nhdjob2tg",ob->query_temp("nhdjobtg"));
me->set_temp("roomjob",local);
message_vision("$n˵��,���պڵ�����Ҫ�д�ٶ������Ʋ��һ��Ҫ������Щ���ˡ�\n", me, ob);
}


if (ob->query_temp("nhdjoblb")=="����׷ɱ")
{
room2=load_object(ob->query_temp("nhdjobtg"));
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/task/boss");
       letter->move(ob->query_temp("nhdjobtg"));
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("killbyn",me->query("id"));
zujinpc(me,letter);	
letter->random_move();
message_vision("$n˵��,��˵���ֹ���:" + letter->query("name") + "��"+room+"�������֡�\n", me, ob);
message_vision("$n˵��,һ��Ҫ������ȥ��ֻҪ�ҵ�������ɱ���ۣ�\n", me, ob);
}		

if (ob->query_temp("nhdjoblb")=="���ڻ���")
{
room2=load_object(ob->query_temp("nhdjobtg"));
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/task/hsnpc");
       letter->move(environment(ob));
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("hstg",ob->query_temp("nhdjobtg"));
letter->set("hsr",me->query("id"));
me->apply_condition("taskjob_busy",22);
message_vision("$n˵��,�ҵ�����:" + letter->query("name") + "�뵽"+room+"ȥ �鷳�㻤��һ�°ɡ�\n", me, ob);
message_vision("$n˵��,ϣ������һ·˳�� ƽ�����\n", me, ob);
}

if (ob->query_temp("nhdjoblb")=="��������")
{
room2=load_object(ob->query_temp("nhdjobtg"));
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/task/boss2");
       letter->move(ob->query_temp("nhdjobtg"));
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("killbyn",me->query("id"));
zujinpc(me,letter);	
letter2 = new("/quest/task/mijian");
letter2->move(letter);
letter2->set("killbyn",ob->query("id"));
letter->random_move();
message_vision("$n˵��,����һ�������" + letter->query("name") + "�����ˣ������һذɡ�\n", me, ob);
message_vision("$n˵��,һ�������������������Ѫ����а�����һ�����档\n", me, ob);
}

if (ob->query_temp("nhdjoblb")=="����̽Ѱ")
{
room2=load_object(ob->query_temp("nhdjobtg"));
local=room2->query("short");
dir2=explode(base_name(room2),"/");
fname=base_name(room2);
zuji(dir2[1]);
room=zuji(dir2[1])+local;
       letter = new("/quest/task/hsnpc");
       letter->move(room2);
       letter->set_name(letter->query("name"),({ me->query("id")+" "+letter->query("id")}));
letter->set("hstg",base_name(environment(ob))+".c");
letter->set("hsr",me->query("id"));
me->apply_condition("taskjob_busy",22);
message_vision("$n˵��,�ҵ�����" + letter->query("name") + "��"+room+" �鷳��������͵�����ɡ�\n", me, ob);
message_vision("$n˵��,һ·˳�� ƽ��������\n", me, ob);
}

if (ob->query_temp("nhdjoblb")=="Ѱ����Ʒ") 
{
ob->set_temp("nhdjobxh",ob->query_temp("nhdjobtg"));
message_vision("$n˵��,����ºܼ�,�뾡����Ҵ����ɡ�\n", me, ob);
}

if (ob->query_temp("nhdjoblb")=="�鱨��̽") 
{
me->set_temp("roomjob",ob->query_temp("nhdjobtg"));
me->set_temp("nhdjob2tg",ob->query_temp("nhdjobtg"));
message_vision("$n˵��,������ټ򵥲�����,�뾡��ȥ��̽�ɡ�\n", me, ob);
}

me->set_temp("nhdjob2lb",ob->query_temp("nhdjoblb"));
me->set_temp("nhdjob2tg",ob->query_temp("nhdjobtg"));
me->set_temp("nhdjob2sc","���յص�:"+envn+":"+" ������:"+ob->query("name")+":"+" ��������:"+ob->query_temp("nhdjobsc"));
ob->delete_temp("nhdjoblb");
ob->delete_temp("nhdjobtg");
ob->delete_temp("nhdjobsc");
ob->delete_temp("nhdjoben");
	 return 1;
}

	if( userp(ob) ) return 1;
	if( !living(ob) ) {
		message_vision("���Ǻ���Ȼ�ģ�$n���ڵ�״��û�а취��$N�κδ𸲡�\n",
			me, ob);
		return 1;
	}
	hydata=year+month+day;
	
		if( (!me->query("jobdata") || me->query("jobdata")!=hydata) && me->is_apprentice_of(ob)   && (topic=="job" || topic=="jobs")) {
		message_vision("$N������������$n��ͷ�밲���е�����ʦ������\n", me, ob);

ob->start_busy(1);
//write(hydata);

    if ( !wizardp(me) && me->query("jobdata")==hydata)
{
		message_vision("$n˵������������񣬲����Ѿ���������? \n", me, ob);
		return 1;
}

if ( me->query("jobdata")!=hydata || wizardp(me))
{
	i=random(9)+1;
	if (me->query("combat_exp",1) < 3000000 ) i=random(4)+1;
	//if (random(2)==0) i=random(4)+1;
	
	if (i==1)
{
	j=10;
	if (me->query("zhuanshen")) j=20;
me->set("jobtime",1);	
me->set("jobtg",j);	
message_vision("$n˵����ʦ���м���Ҫ����ɣ��������� ������������quest��"+chinese_number(j)+"�θ�������(help geren)���ɣ����õļǵ������� (ask about ok) �� \n", me, ob);
}
	if (i==2)
{
	j=20;
	if (me->query("zhuanshen")) j=50;
me->set("jobtime",2);	
me->set("jobtg",j);	
message_vision("$n˵����ʦ���м���Ҫ����ɣ��������� ������������job��"+chinese_number(j)+"�ζ�������(help geren)���ɣ����õļǵ������� (ask about ok) �� \n", me, ob);

}
	if (i==3)
{
	j=1;
	if (me->query("zhuanshen")) j=3;
me->set("jobtime",3);	
me->set("jobtg",j);	
message_vision("$n˵����ʦ���м���Ҫ����ɣ��������� ����սʤ"+chinese_number(j)+"����ң����õļǵ������� (ask about ok)  ��\n", me, ob);

}
	if (i==4)
{
	j=8;
	if (me->query("zhuanshen")) j=16;
	room=family_fame[random(39)];
      //��������	
if (room==me->query("family/family_name")) room=family_fame[random(8)];
if (room==me->query("family/family_name")) room=family_fame[random(16)];
if (room==me->query("family/family_name")) room=family_fame[random(22)];
if (room==me->query("family/family_name")) room=family_fame[random(28)];
if (room==me->query("family/family_name")) room=family_fame[random(33)];
if (room==me->query("family/family_name")) room=family_fame[random(39)];
me->set("jobtime",4);	
me->set("jobtgn",room);	
me->set("jobtg",j);	
message_vision("$n˵����ʦ���м���Ҫ����ɣ��������� ȥ"+room+"�������ɵ�����"+chinese_number(j)+"����(kantou)�� ���üǵ������� (ask about ok)  ��\n", me, ob);

}
	if (i==5)
{
	j=3;
	if (me->query("zhuanshen")) j=8;
me->set("jobtime",5);	
me->set("jobtg",j);	
message_vision("$n˵����ʦ���м���Ҫ����ɣ��������� ���"+chinese_number(j)+"�������س�����(help guojob)�����õļǵ������� (ask about ok) �� \n", me, ob);

}
	if (i==6)
{
	j=3;
		if (me->query("zhuanshen")) j=8;
me->set("jobtime",6);	
me->set("jobtg",j);	
message_vision("$n˵����ʦ���м���Ҫ����ɣ��������� ���"+chinese_number(j)+"��������������(help wangjob)�����õļǵ������� (ask about ok)  ��\n", me, ob);
}
	if (i==7)
{
	j=1;
			if (me->query("zhuanshen")) j=3;
me->set("jobtime",7);	
me->set("jobtg",j);	
message_vision("$n˵����ʦ���м���Ҫ����ɣ��������� ���"+chinese_number(j)+"�ν���ҥ������(help taskjobs)�����������ף����õļǵ������� (ask about ok)  ��\n", me, ob);

}
	if (i==8)
{
	j=3;
				if (me->query("zhuanshen")) j=8;
me->set("jobtime",8);	
me->set("jobtg",j);	
message_vision("$n˵����ʦ���м���Ҫ����ɣ��������� ������������"+chinese_number(j)+"���������(help teamjob)���ɣ����õļǵ������� (ask about ok) ��\n", me, ob);
}

	if (i==9)
{
	j=10;
				if (me->query("zhuanshen")) j=20;
me->set("jobtime",9);	
me->set("jobtg",j);	
message_vision("$n˵����ʦ���м���Ҫ����ɣ��������� ���"+chinese_number(j)+"�ιٸ�����(help guanfu) ���õļǵ������� (ask about ok) �� \n", me, ob);
}

}

me->set("jobdata",hydata);

		return 1;
	}
	
	if( me->is_apprentice_of(ob)   && topic=="ok" && me->query("jobtg") ) {
		message_vision("$N������������$n��ͷ�밲���е�����ʦ������\n", me, ob);

hydata=year+month+day;
//write(hydata);
if (wizardp(me)) message_vision("$N������������$n��ͷ"+me->query("jobtime")+"��"+me->query("jobtg")+"\n", me, ob);

    if ( ! me->query("jobdata") || ! me->query("jobtime"))
{
		message_vision("$n˵������������񣬸�������? \n", me, ob);
		return 1;
}

    if ( (int)me->query("jobtg",1)==0)
{
		message_vision("$n˵������������񣬲����Ѿ������� \n", me, ob);
		return 1;
}

if ( me->query("jobdata") )
{
i=(int)me->query("jobtime",1);
	if (i==1)
{
	k=me->query_temp("mpjobn1",1);
message_vision("$n˵����������������,���Ѿ������"+chinese_number(k)+"������ �� \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn1");
message_vision("$n˵�������Ĳ����Ҿ�ָ���������书�� �� \n", me, ob);
}
}
	if (i==2)
{
	k=me->query_temp("mpjobn3",1);
	message_vision("$n˵������������ ���Ѿ������"+chinese_number(k)+"������ �� \n", me, ob);
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn3");
message_vision("$n˵�������Ĳ����Ҿ�ָ���������书�� �� \n", me, ob);
}
}
	if (i==3)
{
		k=me->query_temp("mpjobn4",1);
		message_vision("$n˵������������ ���Ѿ������"+chinese_number(k)+"������ �� \n", me, ob);
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
me->delete_temp("mpjobn4");
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
message_vision("$n˵�������Ĳ����Ҿ�ָ���������书�� �� \n", me, ob);
}
}
	if (i==4)
{
k=me->query_temp("mpjobn5",1);
message_vision("$n˵������������ ���Ѿ������"+chinese_number(k)+"������ �� \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn5");
message_vision("$n˵�������Ĳ����Ҿ�ָ���������书�� �� \n", me, ob);
}
}
	if (i==5)
{
	k=me->query_temp("mpjobn6",1);
	message_vision("$n˵���������س����� ���Ѿ������"+chinese_number(k)+"������ �� \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn6");
message_vision("$n˵�������Ĳ����Ҿ�ָ���������书�� �� \n", me, ob);
}
}
	if (i==6)
{
		k=me->query_temp("mpjobn7",1);
		message_vision("$n˵���������������� ���Ѿ������"+chinese_number(k)+"������ �� \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn7");
message_vision("$n˵�������Ĳ����Ҿ�ָ���������书�� �� \n", me, ob);
}
}
	if (i==7)
{
		k=me->query_temp("mpjobn8",1);
		message_vision("$n˵������������ ���Ѿ������"+chinese_number(k)+"������ �� \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn8");
message_vision("$n˵�������Ĳ����Ҿ�ָ���������书�� �� \n", me, ob);
}
}
	if (i==9)
{
		k=me->query_temp("mpjobn9",1);
		message_vision("$n˵�����ٸ����� ���Ѿ������"+chinese_number(k)+"������ �� \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn9");
message_vision("$n˵�������Ĳ����Ҿ�ָ���������书�� �� \n", me, ob);
}
}

	if (i==8)
{
		k=me->query_temp("mpjobn2",1);
		message_vision("$n˵��������������� ���Ѿ������"+chinese_number(k)+"������ �� \n", me, ob);	
if (k>=me->query("jobtg",1))
{
	
addnl(me,"exp",8000+random(5888));
addnl(me,"mpgx",3+random(3));
me->set("jobtg",0);	
me->delete_temp("mpjobn2");
message_vision("$n˵�������Ĳ����Ҿ�ָ���������书�� �� \n", me, ob);
}
}

}

me->set("jobdata",hydata);

		return 1;
	}
	
	
	if( msg = ob->query("inquiry/" + topic) ) {
		if( stringp(msg) ) {
			message_vision( CYN "$N˵����" + msg + "\n" NOR, ob);
			return 1;
		}
	} else {
  	        if(ob->query("race")=="Ұ��") {
			message_vision("���Ǻܿ�ϧ��$N����˵����\n", ob);
			return 1;
		}
		switch(topic) {
			case "name":
			message_vision( CYN "$N˵�����ҵ����־���$N," + RANK_D->query_respect(me)+ "��ʲô��?\n" NOR, ob);
				break;
			case "here":
				message_vision(CYN "$n��$N˵����������" + environment(ob)->query("short") + "���������" + RANK_D->query_self(ob) + "Ҳ��̫�����\n" NOR, me, ob);
				break;
			case "rumors":
			message_vision( CYN "$N����˵��,���������˵��:"+str+"" NOR, ob);				break;
			default:
		if(topic=="news")
			{
                        if (!str)
			{
			message_vision( CYN "$N����˵��,���ûʲô���ſ�˵.." NOR, ob);
			}
else {
			message_vision( CYN "$N����˵��,���������˵��:"+str+"" NOR, ob);
}
			return 1;
		}	
		if(topic=="all")
			{
			message_vision( CYN "$N��������˵��:"+query_inquiry(ob)+"!\n" NOR, ob);
			return 1;
		}
				if (topic == ob->query("name") || ob->id(topic))
				message_vision(CYN "$n˵�����Ǿ���" + RANK_D->query_self_rude(ob) + "ѽ��\n" NOR, me, ob);
				else if (topic == me->query("name") || me->id(topic))
				message_vision(CYN "$n˵�����Ǿ���" + RANK_D->query_rude(me) + "��ѽ��\n" NOR, me, ob);
                                else if (topic == ob->query("name") || ob->id(topic))
				EMOTE_D->do_emote(ob, "name1");
else if (ob->query("combat_exp") < 500000)
{
                                if (strsrch(topic,"����")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵���������Ǿ���,��˵�����ǧ��¥����\n" NOR, me, ob);
                                else if (strsrch(topic,"����")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�����˳Ʊ����Ĺ����������ɹųɼ�˼���Ľ���������
�����߹֡�ȫ�������ڵ���������ؤ�����߹��͡�����ͯ���ܲ�ͨ���˵�ͽ�ܣ���������书�\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�������µ�һ�����ɾ������֡��\n" NOR, me, ob);
                                else if (strsrch(topic,"�䵱��")>= 0 || strsrch(topic,"�䵱")>= 0)
                                message_vision(CYN "$n˵�����䵱���������ҵ�ż�񡣡\n" NOR, me, ob);
                                else if (strsrch(topic,"�� ��")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�������µ�һ�̣����˳�ħ�̵����̡��\n" NOR, me, ob);
                                else if (strsrch(topic,"��ɽ��")>= 0 || strsrch(topic,"��ɽ")>= 0)
                                message_vision(CYN "$n˵�������¾Ž��������µ�һ�����\n" NOR, me, ob);
                                else if (strsrch(topic,"����Ľ��")>= 0 || strsrch(topic,"Ľ��")>= 0)
                                message_vision(CYN "$n˵������ʲô������, ��Ҫʲô��������\n" NOR, me, ob);
                                else if (strsrch(topic,"�һ���")>= 0 || strsrch(topic,"�һ�")>= 0)
                                message_vision(CYN "$n˵�����һ����������书���ֶ����ɲ��١��\n" NOR, me, ob);
                                else if (strsrch(topic,"����μ�")>= 0 || strsrch(topic,"������")>= 0)
                                message_vision(CYN "$n˵���������񽣡��貨΢������ѧ�ĸ������أ��\n" NOR, me, ob);
                                else if (strsrch(topic,"ؤ��")>= 0 || strsrch(topic,"ؤ��")>= 0)
                                message_vision(CYN "$n˵�������µ�һ��ô����Ȼ��ؤ���ˡ��\n" NOR, me, ob);
                                else if (strsrch(topic,"��Ĺ")>= 0 || strsrch(topic,"��Ĺ��")>= 0)
                                message_vision(CYN "$n˵����������£�������ʣ���֪��Ĺһ�ɿ��д��ˣ��\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�����������ͨ���ӣ��ڵ��������ٱ�����һ����.....�\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"ѩɽ��")>= 0)
                                message_vision(CYN "$n˵������ѩɽ��������������ȥ�ܾ��ˣ��\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵���������ɶ����ö�����!���޳�֮ͽ�\n" NOR, me, ob);
                                else if (strsrch(topic,"���ư�")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�����Ǻ�צɽ�������ɽ��,������������һ�㡣�\n" NOR, me, ob);
                                else if (strsrch(topic,"��ɽ��")>= 0 || strsrch(topic,"��������")>= 0)
                                message_vision(CYN "$n˵������˵�������ɾ�Ҫ�ϲ��ˡ��\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵��������ɽ��Сʦ���ǿ���Ư���ĺܰ����ٺ١��\n" NOR, me, ob);
                                else if (strsrch(topic,"���չ�")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�������չ��Ͽɶ��Ǵ���Ů��һ������������Ůһ�����\n" NOR, me, ob);
                                else if (strsrch(topic,"����ɽׯ")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵������˵����ɽ���кܶ���,�ÿ��°����\n" NOR, me, ob);
                                else if (strsrch(topic,"��ң��")>= 0 || strsrch(topic,"��ң")>= 0)
                                message_vision(CYN "$n˵������ң�ɺ�������չ����˳����������\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵������������������䡣�ٽ�˫�����\n" NOR, me, ob);
                                else if (strsrch(topic,"������� ")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵�����ճ�������Ψ�Ҳ��ܡ��\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵������������������䡣�ٽ�˫�����\n" NOR, me, ob);
                                else if (strsrch(topic,"������")>= 0 || strsrch(topic,"����")>= 0)
                                message_vision(CYN "$n˵����һ�߽������ǵ��ˣ�����Ļ��������\n" NOR, me, ob);
                                else if (strsrch(topic,"�嶾��")>= 0 || strsrch(topic,"�嶾")>= 0)
                                message_vision(CYN "$n˵��������ÿ��£�ʲô���ﶼ�С��\n" NOR, me, ob);

}
				else
					message_vision(msg_dunno[random(sizeof(msg_dunno))], me, ob);
		}
	}
	return 1;
}

string query_inquiry(object ob)
{
	int i=0;
	mapping inq;
	string str="", *indexs;
	
	if(mapp(inq=ob->query("inquiry")))
		{
		indexs=keys(inq);
		for(i=0;i<sizeof(indexs);i++)
			{
				str=indexs[i]+" "+str;
				}
		str="�й��� "HIB+str+NOR CYN"������,�Һܸ��˸�����!";
		return str;
		}
	return "ʵ���ǶԲ���,��ʲôҲ��֪��ѽ!";
	}

void zujinpc(object me,object obj)
{   

	int maxpot;
	int maxexp;
	int maxskill;
	int i;
        if (!me) return;
	maxskill=1+me->query_skill("force",1)*2/3;
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp",1);
        if (maxskill<100)
        maxskill=100;
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (i==0) i=1;
        if (!i) i=1;


	obj->initlvl(maxskill);
         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("max_qi")*i);
        obj->set("eff_qi", me->query("max_qi")*i);
        obj->set("max_qi", me->query("max_qi")*i);
        obj->set("eff_jing", me->query("max_jing")*i);
        obj->set("max_jing", me->query("max_jing")*i);
        obj->set("jing", me->query("max_jing")*i);
        obj->set("neili", me->query("max_neili")*i);
        obj->set("max_neili", me->query("max_neili")*i);

}

void zujinpc2(object me,object obj)
{   

	int maxpot;
	int maxexp;
	int maxskill;
	int i;
        if (!me) return;
	maxskill=1+me->query_skill("force",1)/2;
	maxpot=me->query_temp("maxpot");
	maxexp=me->query("combat_exp",1);
        if (maxskill<50)
        maxskill=50;
        i=me->query_temp("team_count");
        if (!i) i=sizeof(me->query_team());
        if (i==0) i=1;
        if (!i) i=1;


	obj->initlvl(maxskill);
         obj->set("combat_exp",maxexp);
        obj->set("str", me->query("str"));
        obj->set("dex", me->query("dex"));
        obj->set("per", me->query("per"));
        obj->set("qi", me->query("max_qi")*i);
        obj->set("eff_qi", me->query("max_qi")*i);
        obj->set("max_qi", me->query("max_qi")*i);
        obj->set("eff_jing", me->query("max_jing")*i);
        obj->set("max_jing", me->query("max_jing")*i);
        obj->set("jing", me->query("max_jing")*i);
        obj->set("neili", me->query("max_neili")*i);
        obj->set("max_neili", me->query("max_neili")*i);

}

string  zuji(string str)
{   
string output;
      	if (str=="baituo")  

	output="����ɽ";

if (str=="binghuodao")  

	output="����";

if (str=="city")  

	output="����";

if (str=="city2" || str=="beijing"  || str=="huanggon"  || str=="huanggong" || str=="beihai")  

	output="������";

if (str=="city4" || str=="changan")   

	output="������";

if (str=="dali")  

	output="����";

if (str=="emei")  

	output="��üɽ";

if (str=="foshan")  

	output="��ɽ";

if (str=="gaibang")  

	output="ؤ��";

if (str=="gaochang")  

	output="�߲��Թ�";

if (str=="guanwai")  

	output="����";

if (str=="guiyun")  

	output="����ׯ";

if (str=="gumu")  

	output="��Ĺ��";

if (str=="hangzhou")  

	output="����";

if (str=="heimuya")  

	output="��ľ��";

if (str=="hengshan")  

	output="��ɽ";

if (str=="henshan")  

	output="��ɽ";

if (str=="huanghe")  

	output="�ƺӾ���";

if (str=="huashan")  

	output="��ɽ";

if (str=="jinshe")  

	output="����ɽ��";

if (str=="lingjiu")  

	output="���չ�";

if (str=="lingzhou")  

	output="����";

if (str=="meizhuang")  

	output="÷ׯ";

if (str=="mingjiao")  

	output="����";

if (str=="qingcheng")  

	output="���ɽ";

if (str=="quanzhen")  

	output="ȫ����";

if (str=="quanzhou")  

	output="Ȫ��";

if (str=="shaolin")  

	output="������";

if (str=="shenlong")  

	output="������";

if (str=="songshan")  

	output="��ɽ";

if (str=="suzhou")  

	output="����";

if (str=="taishan")  

	output="̩ɽ";

if (str=="taohua")  

	output="�һ���";

if (str=="tianlongsi")  

	output="������";

if (str=="wanjiegu")  

	output="��ٹ�";

if (str=="wudang")  

	output="�䵱ɽ";

if (str=="xiakedao")  

	output="���͵�";

if (str=="xiangyang")  

	output="������";

if (str=="xiaoyao")  

	output="��ң��";

if (str=="xingxiu")  

	output="���޺�";

if (str=="xueshan")  

	output="ѩɽ��";

if (str=="xuedao")  

	output="��ѩɽ";

if (str=="mr")  

	output="Ľ������";

if (str=="kunlun")  

	output="����ɽ";

if (str=="tiezhang")  

	output="������";

if (str=="huizhu")  

	output="���岿��";

if (str=="yinju")  

	output="һ�ƴ�ʦ��";

if (str=="menggu")  

	output="�ɹŲ�ԭ";

if (str=="qianjin")  

	output="����ǧ��¥";

if (str=="lingshedao")  

	output="���ߵ�";

if (str=="ruzhou")  

	output="���ݳ�";

if (str=="kunming")  

	output="����";

if (str=="jingzhou")  

	output="����";

if (str=="yanjing")  

	output="ʢ��";

if (str=="lanzhou" || str=="lanzhouchen")  

	output="����";

if (str=="jyguan")  

	output="������";

if (str=="changcheng")  

	output="����";

if (str=="fairyland")  

	output="��÷ɽׯ";

if (str=="sdxl")  

	output="��ħ�������Ĺ";

if (str=="jqg")  

	output="�����";

if (str=="nio")  

	output="ţ�Ҵ�";

if (str=="feihu")  

	output="��������";

if (str=="wuguan")  

	output="�������";

if (str=="village")  

	output="��ɽ��";

if (str=="taohuacun")  

	output="�һ���";

if (str=="pingan")  

	output="ƽ����";

if (str=="lingxiao")  

	output="������";

if (str=="wudujiao")  

	output="�嶾��";

if (str=="hj")  

	output="��ɽ��ԭ";
if (str=="dali/yuxu")  

	output="���������";
if (str=="dali/wuliang")  

	output="��������ɽ";
if (str=="huanghe/yyd")  

	output="�ƺ�����";
if (str=="kaifeng")  

	output="�����";
if (str=="feitian")  

	output="����������";
if (str=="japan")  

	output="�ձ���";
if (str=="tangmen")  

	output="����";
if (str=="luoyang")  

	output="������";

if (str=="chengdu" || str=="city3")  

	output="�ɶ�";

if (str=="baihuagu")  

	output="�ٻ���";

if (str=="heizhao")  

	output="�ٻ��Ⱥ���";

if (str=="jiaxing")  

	output="����";

if (str=="shiliang")  

	output="�¼�ׯ";

if (str=="wuyi")  

	output="����ɽ��";

if (str=="yanping")  

	output="��ƽ��";
	

if (str=="jiangling")  
{
	output="�����";
}

if (str=="yueyang")  
{
	output="������";	
}

if (str=="qilian")  
{
	output="����ɽ";	
}

if (str=="shouxihu")  
{
	output="������";	
}

if (str=="wuxi")  
{
	output="������";	
}

if (str=="yixing")  
{
	output="���˳�";	
}
if (str=="taiwan")  
{
	output="̨��";	
}
if (str=="nanyang")  
{
	output="����";	
}
if (str=="nanshaolin")  
{
	output="������";	
}

if (str=="cangzhou")  
{
	output="����";	
}

if (str=="tanggu")  
{
	output="������";	
}

if (str=="yunhe")  
{
	output="�����˺�";	
}

if (str=="hainan")  
{
	output="���ϵ�";	
}

if (str=="jindezheng")  
{
	output="������";	
}

if (str=="yandang")  
{
	output="�㵴ɽ";	
}

if (str=="jinling")  
{
	output="�����";	
}

if (str=="sandboy")  
{
	output="����ũ��";	
}

if (str=="huangshan")  
{
	output="��ɽ";	
}

if (str=="yubifeng")  
{
	output="��ʷ�";	
}

if (str=="quanzhouchen")  
{
	output="Ȫ�ݳ���";	
}

if (str=="qingzh")  
{
	output="��ظ�ԭ";	
}

if (str=="changbaishan" || str=="gaoli")  
{
	output="��������ɽ";	
}

if (str=="annan")  
{
	output="����";	
}

if (str=="taiyuan")  
{
	output="̫ԭ";	
}

if (str=="hefei")  
{
	output="�Ϸ�";	
}

if (str=="jiujiang")  
{
	output="�Ž�";	
}

if (str=="baling")  
{
	output="����";	
}

if (str=="xinjiang")  
{
	output="�½�";	
}
if (str=="dingxiang")  
{
	output="����";	
}
if (str=="suiye")  
{
	output="��Ҷ";	
}
if (str=="lumaji")
{
	output="¹��";	
}


if (str=="houjizhen")
{
	output="���";	
}

if (str=="zuojiacun")
{
	output="��ͤ��";	
}

if (str=="biancheng")
{
	output="�߳�";	
}


if (str=="jinghai")
{
	output="������";	
}


if (str=="huayin")
{
	output="ͭɽ��";	
}

if (str=="xiyu")
{
	output="��������";	
}

if (str=="heifeng")
{
	output="�ڷ�կ";	
}
if (str=="linzhi")
{
	output="������֥����";	
}


if (str=="cloud" )  
{
	output="���������";	
}

if (str=="xinan")
{
	output="��������";	
}

if (str=="mayi")  
{
	output="���ر߽�";	
}
if (str=="xuzhou")  
{
	output="���ݳ�";	
}
if (str=="jinan")  
{
	output="���ϳ�";	
}
if (str=="guizhou")  
{
	output="������";	
}

if (str=="nanchang")  
{
	output="�ϲ���";	
}


if (str=="changsha")  
{
	output="��ɳ��";	
}


if (str=="zhongzhou")  
{
	output="���ݳ�";	
}

if (str=="xizang" || str=="zangbei")  
{
	output="���ػ�ر�";	
}

if (str=="tianshui")  
{
	output="��ˮ��";	
}

if (str=="datong")  
{
	output="��ͬ��";	
}
if (str=="ny")  
{
	output="��Զ��";	
}
if (str=="fengtian")  
{
	output="ʢ����";	
}

if (str=="yanmen")  
{
	output="���Ź�";	
}
if (str=="cloud")  
{
	output="�����";	
}
if (str=="xueting")  
{
	output="ѩͤ��";	
}
if (str=="fuzhou")  
{
	output="����";	
}
if (str=="welcome")  
{
	output="�Ŵ�";	
}
if (!output)  
{
	output="δ֪����";	
}

if (output=="")  
{
	output="δ֪����";	
}


return output;
}

int sort_user(object ob1, object ob2)
{
	if( wizardp(ob1) && !wizardp(ob2) ) return -1;
	if( wizardp(ob2) && !wizardp(ob1) ) return 1;
	if( wizardp(ob1) && wizardp(ob2) )
		return (int)SECURITY_D->get_wiz_level(ob2) 
			- (int)SECURITY_D->get_wiz_level(ob1);
	
	return (int)ob2->query("mud_age") - (int)ob1->query("mud_age");
}

int help(object me)
{
   write( @HELP
ָ���ʽ: ask <someone> about <something>

���ָ���ڽ���ʱ����Ҫ, ͨ��������ɴ�һָ�����
��ý�һ������Ѷ��
Ԥ���ѯ������:
	here
	name
	news
	all
HELP
   );
   return 1;
}
