uyer baseBuyer(id, name, bank.getAccountById(id));
                                Seller newSeller(baseBuyer, sellerId, sellerName);
                                bank.addSeller(newSeller);
