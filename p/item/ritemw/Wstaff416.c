// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit STAFF;

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

void create()
{
	set_name("[1;37m°ËØÔÖ®ÕÈ[2;37;0m", ({ "bagua staff", "staff" }));
	set_weight(6231);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¸ù");
		set("long", @LONG
[1;37m°ËØÔÓĞ¡°Ğİ¡±¡°Éú¡±¡°ÉË¡±¡°¶Å¡±¡°ËÀ¡±¡°¾°¡±¡°¾ª¡±¡°¿ª¡±Ö®±ğ£¬´´×ÔÖî¸ğÎäºò£¬¼¯ÌìÏÂÍò±äÓÚÒ»Éí£¡
[2;37;0mÕâÊÇÒ»¸ùÓÉÎŞ±È¼áÓ²µÄ[31mÁ÷»¨Ê¯[2;37;0mÖÆ³É£¬ÖØÊ®¶ş½ïËÄÁ½ÁùÇ®µÄ[1;37m°ËØÔÖ®ÕÈ[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;35m¾øÊÀº±¼û[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[36mÄ¾[2;37;0m:[31m¾«ÖÂ[2;37;0m [32mË®[2;37;0m:[31m¾«ÖÂ[2;37;0m [37mÌì[2;37;0m:[1;31m´´ÊÀ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ÌìÁé:[34mÏ¸Ëé[2;37;0m ¾ø´ú:[34mÏ¸Ëé[2;37;0m ³¤Éú:[1;36mÍêÃÀ[2;37;0m ²»ÀÏ:[34mÏ¸Ëé[2;37;0m 

LONG
);
    set("no_get",1);
	  set("no_put",1);
	  set("no_pawn",1);
	  set("no_drop",1);
	  set("no_beg",1);
	  set("no_steal",1);
	  set("systemmake",1);
		set("value", 25000);
		set("weapon_prop/intelligence",25);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",26);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",0);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 0);
    set("weapon_prop/qi", 70);
    set("weapon_prop/jing", 29);
    set("weapon_prop/jingli", 29);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",6);
    set("wtypeC",6);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",0);
    set("wtypeI",14);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "throwing",
                        "exp_required": 80000,
                        "difficulty": 85,
                        "min_skill":  1,
                        "max_skill": 300,              
                ]) );		
		set("base_unit", "·¢");
		

		set("hxweapon", 1);
		set("material", "default");
    set("sharpness", 22);

		set("wield_msg", "$N½«$nÎÕÔÚÊÖÖĞ¡£\n");
		set("unwield_msg", "$N½«ÊÖÖĞµÄ$n·ÅÏÂ¡£\n");
	}
	
	init_staff(944);
	setup();
}



#include "/obj/ritem/weaponzy.h";