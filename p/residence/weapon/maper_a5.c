#include <ansi.h> 
#include <armor.h>

inherit HANDS;

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
	      set_name("[1;33m��˿����[2;37;0m", ({ "fengyun hands", "hands" }));
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
		set("long", @LONG
[1;35m��ν���Ƽʻᣬ��ر�ɫ���̴���ǧ���ħС����һ����
[2;37;0m����һ�����൱��Ӳ��[37m����[2;37;0m����[1;37m����˿[2;37;0m�Ƴɣ����Ľ�������Ǯ��[1;35m����֮����[2;37;0m��
�ۺ�����[1;36m��˫�޶�[2;37;0m �������൱��̣�����[34m����[2;37;0m�ķ�������
������˼����ŷ��ţ�
[37m��[2;37;0m:[1;36m����[2;37;0m [36mľ[2;37;0m:[1;34m����[2;37;0m [32mˮ[2;37;0m:[1;31m����[2;37;0m [31m��[2;37;0m:[1;31m��Ԫ[2;37;0m 
���滹����һЩ���֣�
��Ӳ:[1;33m����[2;37;0m ����:[35m��׼[2;37;0m ����:[32m�ֲ�[2;37;0m ����:[33m�ܸ�[2;37;0m 
��ʯ:[31m����[2;37;0m ����:[31m����[2;37;0m 
����:[32m�ֲ�[2;37;0m 
�Լ�һ�Ź�׭�֡� [1;32m��ͼһ��[2;37;0m ������һЩ�� [1;32mָ��[2;37;0m ���ļ��ɡ�

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
		set("armor_prop/intelligence",56);
		set("armor_prop/strength",56);
		set("armor_prop/karey",48);
		set("armor_prop/percao",48);
		set("armor_prop/dexerity",48);
		set("armor_prop/constitution",48);
    set("armor_prop/dodge", 56);
    set("armor_prop/parry", 63);
    set("armor_prop/attack", 64);


    set("armor_prop/armor", 845);
    set("armor_prop/defense", 56);
    
    set("armor_prop/neili", 48);
    set("armor_prop/qi", 56);
    set("armor_prop/jing", 56);
    set("armor_prop/jingli", 48);
    set("armor_prop/damage", 1486);

    set("wtypeA",6);
    set("wtypeB",8);
    set("wtypeC",14);
    set("wtypeD",13);
    set("wtypeE",6);
    set("wtypeF",6);
    set("wtypeG",7);
    set("wtypeH",0);
    set("wtypeI",7);
    set("wtypeJ",7);
    set("wtypeK",6);
    set("wtypeL",7);
    
    
                set("skill", ([
                        "name": "finger",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		


		set("material", "default");
    set("sharpness", 16);
        }
        setup();
}

int query_autoload() { return 1; }

#include "/obj/armorzy.h";