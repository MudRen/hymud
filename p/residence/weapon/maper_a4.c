#include <ansi.h> 
#include <armor.h>

inherit WRISTS;

string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"x2_poison",
"sanpoison",
"scorpion_poison",
"anqi_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
"xscold_poison",
});

string *order = ({""HIY"", ""HIG"", ""RED"", ""MAG"", ""YEL"", ""HIC"", ""HIW"", ""HIR"",""HIB"", ""CYN"",""WHT"",""HIM"",""BLU""});  
void create()
{
	      set_name("[31m��������[2;37;0m", ({ "tiandi wrists", "wrists" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "˫");
		set("long", @LONG
[1;36m���֮����Ů洲��������µ���ؼ�����֮��֮һ��ǧ���������ƣ����ܿ������أ�
[2;37;0m����һ˫�ɼ����Ӳ��[37m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ�������������Ǯ��[1;36m���֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �����������̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;33m��ʥ[2;37;0m [33m��[2;37;0m:[1;32mħ��[2;37;0m [1;35m��[2;37;0m:[1;31m��Ԫ[2;37;0m 
[1;37m��[2;37;0m:[1;35m����[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;31m����[2;37;0m ����:[1;36m����[2;37;0m 
��ʯ:[1;36m����[2;37;0m ����:[31m����[2;37;0m 
����:[35m��׼[2;37;0m ����:[33m�ܸ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ͼһ��[2;37;0m ������һЩ�� [1;32m�ڹ�[2;37;0m ���ļ��ɡ�

LONG
);
			set("no_get",1);
	set("no_drop",1);
	set("no_put",1);
	set("no_beg",1);
	set("no_steal",1);
	set("ownmake",1);
		set("makeritem",1);
		set("owner", "maper");
		set("ownername", "��ͼһ��");
		set("value", 25000);
		set("armor_prop/intelligence",48);
		set("armor_prop/strength",48);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",0);
		set("armor_prop/constitution",0);
    set("armor_prop/dodge", 0);
    set("armor_prop/parry", 72);
    set("armor_prop/attack", 65);


    set("armor_prop/armor", 377);
    set("armor_prop/defense", 48);
    
    set("armor_prop/neili", 51);
    set("armor_prop/qi", 46);
    set("armor_prop/jing", 0);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 235);

    set("wtypeA",5);
    set("wtypeB",5);
    set("wtypeC",5);
    set("wtypeD",5);
    set("wtypeE",9);
    set("wtypeF",13);
    set("wtypeG",11);
    set("wtypeH",0);
    set("wtypeI",10);
    set("wtypeJ",0);
    set("wtypeK",6);
    set("wtypeL",6);
    
    
                set("skill", ([
                        "name": "force",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 15);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";