// gangjian.c

#include <ansi.h>
#include <weapon.h>

//inherit M_WEAPON;
//inherit F_GEMS;
inherit CLUB;

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
	set_name("[1;36mÀ¥ÂØÖ®¹÷[2;37;0m", ({ "kunlun club", "club" }));
	set_weight(1872);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "¸ù");
		set("long", @LONG
[1;36m	Ğ¦½­ºşÀË¼£Ê®ÄêÓÎ£¬¿Õ¸ºÉÙÄêÍ·¡£
	¶ÔÍ­ÍÓÏï²´£¬Ò÷ÇéÃìÃì£¬ĞÄÊÂÓÆÓÆ£¡ 
	¾ÆÁîÊ«²ĞÃÎ¶Ï£¬ÄÏ¹úÕıÇå³î¡£ 
	°Ñ½£ÆàÈ»Íû£¬ÎŞ´¦ÕĞ¹éÖÛ¡£ 
 
	Ã÷ÔÂÌìÑÄÂ·Ô¶£¬ÎÊË­Áô³şÅå£¬ÅªÓ°ÖĞÖŞ£¿
	ÊıÓ¢ĞÛ¶ùÅ®£¬¸©Ñö¹Å½ñ³î¡£
	ÄÑÏûÊÜµÆ»èÂŞÕÊ£¬Øöê¼»¨Ò»ÏÖºŞÄÑĞİ£¡
	Æ®Áã¹ß£¬½ğ¸êÌúÂí£¬Æ´Ôá»ÄÇğ£¡ 
[2;37;0mÕâÊÇÒ»¸ùÓÉÎŞ±È¼áÓ²µÄ[31mÁ÷»¨Ê¯[2;37;0mÖÆ³É£¬ÖØÈı½ïÆßÁ½ËÄÇ®µÄ[1;36mÀ¥ÂØÖ®¹÷[2;37;0m¡£
×ÛºÏÆÀ¼Û[1;36mÎŞË«ÎŞ¶Ô[2;37;0m ¿´ÆğÀ´ÎŞ±È·æÀû£¬¾ßÓĞ[1;32m¿ªÌìÅüµØ[2;37;0mµÄÍşÁ¦£¡
ÉÏÃæ¿ÌÁË¼¸¸ö¹Å·ûºÅ£º
[32mË®[2;37;0m:[35m±ê×¼[2;37;0m [1;34mµç[2;37;0m:[31m¾«ÖÂ[2;37;0m 
ÉÏÃæ»¹¿ÌÁËÒ»Ğ©·û×Ö£º
·æÀû:[1;33mÃğÊÀ[2;37;0m ¾ø´ú:[34mÏ¸Ëé[2;37;0m ÌìĞş:[32m´Ö²Ú[2;37;0m ÖÜÌì:[33mºÜ¸ß[2;37;0m ³¤Éú:[33mºÜ¸ß[2;37;0m ²»ÀÏ:[32m´Ö²Ú[2;37;0m 

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
		set("weapon_prop/intelligence",0);
		set("weapon_prop/strength",0);
		set("weapon_prop/karey",0);
		set("weapon_prop/percao",25);
		set("weapon_prop/dexerity",0);
		set("weapon_prop/constitution",35);
    set("weapon_prop/dodge", 0);
    set("weapon_prop/parry", 0);
    set("weapon_prop/attack", 0);
    set("weapon_prop/armor", 0);
    set("weapon_prop/defense", 0);
    
    set("weapon_prop/neili", 45);
    set("weapon_prop/qi", 42);
    set("weapon_prop/jing", 35);
    set("weapon_prop/jingli", 35);
    set("weapon_prop/damage", 0);

    set("wtypeA",0);
    set("wtypeB",0);
    set("wtypeC",5);
    set("wtypeD",0);
    set("wtypeE",0);
    set("wtypeF",0);
    set("wtypeG",0);
    set("wtypeH",6);
    set("wtypeI",0);
    set("wtypeJ",0);
    set("wtypeK",0);
    set("wtypeL",0);
    

                set("skill", ([
                        "name": "cuff",
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
	
	init_club(784);
	setup();
}



#include "/obj/ritem/weaponzy.h";