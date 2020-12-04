// skills.c

#include <ansi.h>

inherit F_CLEAN_UP;

string *skill_level_desc = ({
        BLU "��ѧէ��" NOR,		BLU "�����ž�" NOR,        BLU "��ͨƤë" NOR,
        HIB "��֪һ��" NOR,     HIB "��������" NOR,        HIB "������" NOR,
        YEL "����С��" NOR,     YEL "����С��" NOR,        YEL "����Ѿ�" NOR,
        YEL "�������" NOR,     YEL "��Ȼ����" NOR,        YEL "�������" NOR,
        CYN "���д��" NOR,     CYN "���д��" NOR,        CYN "�������" NOR,
        CYN "�޿�ƥ��" NOR,		CYN "����似" NOR,        HIC "�����뻯" NOR,
        HIC "��Ȼ��ͨ" NOR,     HIC "�Ƿ��켫" NOR,        HIC "����Ⱥ��" NOR,
        HIC "������˫" NOR,     HIC "һ����ʦ" NOR,        HIC "������" NOR,
        HIC "����Ⱥ��" NOR,     HIC "��������" NOR,        HIC "��������" NOR,
        HIY "��������" NOR,     HIY "��ɲ�" NOR,        HIY "���ӹ���" NOR, 
        HIY "�����޵�" NOR
});

string *knowledge_level_desc = ({
        BLU "��ѧէ��" NOR,        BLU "��������" NOR,        BLU "��֪����" NOR,
        HIB "ƽ������" NOR,        HIB "˾�ռ���" NOR,        HIB "�����ž�" NOR,
        MAG "��֪һ��" NOR,        MAG "é���ٿ�" NOR,        MAG "��ʶ֮��" NOR,
        YEL "��������" NOR,        YEL "������" NOR,        YEL "�ᳵ��·" NOR,
        HIM "��������" NOR,        HIM "������ͨ" NOR,        HIM "����ǳ��" NOR,
        CYN "����С��" NOR,        CYN "�������" NOR,        CYN "��Ȼ���" NOR,
        CYN "����ʶ��" NOR,        CYN "������ͨ" NOR,        CYN "׿����Ⱥ" NOR,
        HIC "��������" NOR,        HIC "��Ȼ��ͨ" NOR,        HIC "����ͨ��" NOR,
        HIC "������" NOR,        HIC "��Ⱥ����" NOR,        HIC "������˫" NOR,
        HIY "��������" NOR,        HIY "������" NOR,        HIY "������ʥ" NOR,
        HIY "��ɲ�" NOR
});

string skill_level(string, int);

int main(object me, string arg)
{
        object ob;
                object *list, couple_ob;
        mapping skl, lrn, map;
        string *sname, *mapped,target,cardname;
        string *sk;
        int i,j,marry_flag;
        


        seteuid(getuid());

        if(!arg)
                ob = me;
        else{
                ob = present(arg, environment(me));
//        if ( ob->query("SPSKILLS",1)  ) return ob->skills();           
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
                if (!ob) return notify_fail("��Ҫ�쿴˭�ļ��ܣ�\n");
        }

target = (string) me->query("couple/couple_id");	
	if(stringp(target)) couple_ob = find_player(target);
	if( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me)
	&& !me->is_apprentice_of(ob) && ob!=couple_ob
	&& !ob->query("skill_public")
	&& !ob->query("pubmaster") )
		return notify_fail("ֻ�й������ʦͽ��ϵ�����ܲ쿴���˵ļ��ܡ�\n");
			//Add !me->visible(me) by play 2002.7.28  
			// temp removed !me->visible(me) because bug by Xuanyuan

        skl = ob->query_skills();
        if(!sizeof(skl)) {
                write("$ski#"+(ob==me ? "��" : ob->name()) + "Ŀǰ��û��ѧ���κμ��ܡ�\n");
                return 1;
        }
        write("$ski#"+ (ob==me ? "��" : ob->name()) +"Ŀǰ��ѧ���ļ��ܣ�����"+chinese_number(sizeof(skl))+"��ܣ�                               \n\n");
        sname  = sort_array( keys(skl), (: strcmp :) );
        
        map = ob->query_skill_map();
        if( mapp(map) ) mapped = values(map);
        if( !mapped ) mapped = ({});

        lrn = ob->query_learned();
        if( !mapp(lrn) ) lrn = ([]);
        j=0;

        for(i=0; i<sizeof(skl); i++) {
                if(SKILL_D(sname[i])->type()=="knowledge"){
                j=j+1;
                }
        }
        if(j>0) { printf("$ski#��%16s  ������������������������������������������������\n", ""+chinese_number(j)+"��֪ʶ");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type()=="knowledge"){
                printf("$ski#��%s%s%-40s" NOR " - %-10s %3d/%6d��\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("$ski#��������������������������������������������������������������������\n");}

	j=0;
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" || sname[i] == "kick" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "swimming" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "unarmed"|| sname[i] == "beidou-zhenfa" )){
        	j=j+1;
                }
        }
        if(j>0) { printf("$ski#��%16s  ������������������������������������������������\n", ""+chinese_number(j)+"���������");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] == "force" || sname[i] == "cuff" || sname[i] == "strike" || sname[i] == "finger" || sname[i] == "claw" || sname[i] == "hand" || sname[i] == "kick" || sname[i] == "sword" || sname[i] == "blade" || sname[i] == "club" || sname[i] == "pike" || sname[i] == "staff" || sname[i] == "stick" || sname[i] == "hook" ||  sname[i] == "dodge" ||  sname[i] == "parry" || sname[i] == "whip" || sname[i] == "hammer" || sname[i] == "begging" || sname[i] == "training" || sname[i] == "checking" || sname[i] == "digging" || sname[i] == "swimming" || sname[i] == "feixing-shu" || sname[i] == "archery" || sname[i] == "throwing" || sname[i] == "jinshe-zhuifa" || sname[i] == "axe" || sname[i] == "unarmed"|| sname[i] == "beidou-zhenfa" )){
                printf("$ski#��%s%s%-40s" NOR " - %-10s %3d/%6d��\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("$ski#��������������������������������������������������������������������\n");}

	j=0;
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "unarmed" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming" && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe" && sname[i] != "beidou-zhenfa" )){
        	j=j+1;
                }
        }
        if(j>0) { printf("$ski#��%16s  ������������������������������������������������\n", ""+chinese_number(j)+"�����⹦��");}
        for(i=0; i<sizeof(skl); i++) {
        	if(SKILL_D(sname[i])->type() != "knowledge" && (sname[i] != "force" && sname[i] != "cuff" && sname[i] != "strike" && sname[i] != "unarmed" && sname[i] != "finger" && sname[i] != "claw" && sname[i] != "hand" && sname[i] != "kick" && sname[i] != "sword" && sname[i] != "blade" && sname[i] != "club" && sname[i] != "pike" && sname[i] != "staff" && sname[i] != "stick" && sname[i] != "hook" && sname[i] != "dodge" && sname[i] != "parry" && sname[i] != "whip" && sname[i] != "hammer" && sname[i] != "begging" && sname[i] != "training" && sname[i] != "checking" && sname[i] != "digging" && sname[i] != "swimming"  && sname[i] != "feixing-shu" && sname[i] != "archery" && sname[i] != "throwing" && sname[i] != "jinshe-zhuifa" && sname[i] != "axe" && sname[i] != "beidou-zhenfa" )){
                printf("$ski#��%s%s%-40s" NOR " - %-10s %3d/%6d��\n", 
                        (member_array(sname[i], mapped)==-1? "  ": "��"),
                        ((lrn[sname[i]] >= (skl[sname[i]]+1) * (skl[sname[i]]+1)) ? HIM : ""),
                        (to_chinese(sname[i]) + " (" + sname[i] + ")"),
                        skill_level(SKILL_D(sname[i])->type(), skl[sname[i]]),
                        skl[sname[i]], (int)lrn[sname[i]]
                );
                }
        }
        if(j>0) { write("$ski#��������������������������������������������������������������������\n");}
        return 1;
}

string skill_level(string type, int level)
{
        int grade;

        grade = level / 40;

        switch(type) {
                case "knowledge":
                        if( grade >= sizeof(knowledge_level_desc) )
                                grade = sizeof(knowledge_level_desc)-1;
                        return knowledge_level_desc[grade];
                default:
                        if( grade >= sizeof(skill_level_desc) )
                                grade = sizeof(skill_level_desc)-1;
                        return skill_level_desc[grade];
        }
}

int help(object me)
{
        write(@HELP
ָ���ʽ : skills|cha [<ĳ��>]

���ָ���������(��)��ѯ��ѧ���ļ��ܡ�

��Ҳ����ָ��һ��������ʦͽ��ϵ�Ķ����� skills ���Բ�֪�Է��ļ���״����

��ʦ���Բ�ѯ�κ��˻� NPC �ļ���״����

HELP
    );
    return 1;
}
